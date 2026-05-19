class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

    bool valid(int x, int y){
        return (x>-1 && x<m)&&(y>-1 && y<n);
    }
    
    void bfs(vector<vector<bool>>& vis, bool o, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) vis[i][o*(n-1)]=1, q.push({i,o*(n-1)});
        for(int j=0;j<n;j++) vis[o*(m-1)][j]=1, q.push({o*(m-1),j});
        int lvl=q.size();
        while(!q.empty()){
            while(lvl--){
                int x=q.front().first, y=q.front().second;q.pop();
                if(!valid(x,y)) continue;
                for(auto d:dir){
                    int x1=x+d.first, y1=y+d.second;
                    if(!valid(x1,y1) || vis[x1][y1] || grid[x1][y1]<grid[x][y]) continue;
                    vis[x1][y1]=1; //pushed into altq
                    q.push({x1,y1});
                }
            }
            lvl = q.size();
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        if(m==1 || n==1){
            vector<vector<int>> res;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    vector<int> tmp = {i,j};
                    res.push_back(tmp);
                }
            }
            return res;
        }
        vector<vector<bool>> atl(m,vector<bool>(n)), pc(m,vector<bool>(n));
        bfs(atl,1,grid), bfs(pc,0,grid);
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((atl[i][j]==1)&&(pc[i][j]==1)){
                    vector<int> tmp = {i, j};
                    res.push_back(tmp);
                }
            }
        }

/*  
        cout<<"atl\n";
        for(auto v:atl){
            for(auto num:v) cout<<num<<' ';
            cout<<"\n";
        }
        cout<<"\n";
        cout<<"pc\n";
        for(auto v:pc){
            for(auto num:v) cout<<num<<' ';
            cout<<"\n";
        }
*/

        return res;
    }
};
