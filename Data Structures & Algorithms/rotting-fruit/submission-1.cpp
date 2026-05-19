class Solution {
public:
    bool valid(int x, int y, int m, int n){
        return (x>-1 && x<m)&&(y>-1 && y<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=2) continue;
                q.push({i,j});
                vis[i][j]=1;
            }
        }
        int t = 0, lvl=q.size();
        while(!q.empty()){
            while(lvl--){ //process one layer at a time
                int x=q.front().first, y=q.front().second;q.pop();
                if(!valid(x,y,m,n) || grid[x][y]!=2) continue; //only rotten to pop
                for(auto d:dir){
                    int x1=x+d.first, y1=y+d.second;
                    if(!valid(x1,y1,m,n) || vis[x1][y1] || grid[x1][y1]!=1) continue; //only fresh to push
                    vis[x1][y1]=1;
                    grid[x1][y1]=2; //fresh->rotten
                    q.push({x1,y1});
                }
            }
            lvl = q.size();
            if(lvl>0) t++; //some fresh orages were made rotten
        }
        bool fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                fresh|=(grid[i][j]==1);
            }
        }
        if(!fresh) return t;
        else return -1;
    }
};
