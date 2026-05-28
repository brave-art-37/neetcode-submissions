class Solution {
public:
    int m, n;
    bool valid(int x, int y){
        return (x>-1 && x<m)&&(y>-1 && y<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size(), n=grid[0].size();
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,0}});dist[0][0]=grid[0][0];
        while(!pq.empty()){
            int d = pq.top().first;
            auto [x,y] = pq.top().second; pq.pop();
            if(-d>dist[x][y]) continue; //old data
            vis[x][y]=1;
            for(auto d:dir){
                int x1=x+d.first, y1=y+d.second;
                if(!valid(x1,y1) || vis[x1][y1]) continue;
                int val = max(dist[x][y],grid[x1][y1]);
                if(val>=dist[x1][y1]) continue; //no improve
                dist[x1][y1]=val;
                pq.push({-val,{x1,y1}});
            }
            /*
            cout<<"dist:\n";
            for(auto v:dist){
                for(int num:v) cout<<num<<' ';
                cout<<"\n";
            }
            cout<<"\n";
            */
        }
        return dist[m-1][n-1];
    }
};