class Solution {
public:
    vector<pair<int,int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1}};
    bool valid(int x, int y, vector<vector<int>>& grid){
        return (x>-1 && x<grid.size())&&(y>-1 && y<grid[0].size());
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        queue<pair<int,int>> q;
        //simult bfs from all treas
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]!=0) continue; //not a treas
                q.push({row,col});
            }
        }
        int lvl = q.size();
        while(!q.empty()){
            while(lvl--){
                auto x = q.front().first, y = q.front().second; q.pop();
                if(!valid(x,y,grid) || grid[x][y]<0 || vis[x][y]) continue;
                vis[x][y]=1;
                for(auto d:dir){
                    int x1 = x+d.first, y1=y+d.second;
                    if(!valid(x1,y1,grid)) continue;
                    grid[x1][y1] = min(grid[x1][y1],grid[x][y]+1);
                    if(!vis[x1][y1]) q.push({x1,y1});
                }
            }
            lvl=q.size();
        }
    }
};
