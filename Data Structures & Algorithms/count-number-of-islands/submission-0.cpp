class Solution {
public:
    vector<vector<int>> color;
    vector<pair<int,int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0}};
    int num;
    bool valid(int x, int y){
        return (x>-1 && x<color.size())&&(y>-1 && y<color[0].size());
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        color = vector<vector<int>>(m,vector<int>(n));
        num = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(color[i][j]!=0 || grid[i][j]=='0') continue;
                num++;
                stack<pair<int,int>> st;
                st.push({i,j});
                while(!st.empty()){
                    int x = st.top().first, y=st.top().second; st.pop();
                    if(color[x][y]!=0 || grid[x][y]=='0') continue;
                    color[x][y]=num;
                    for(auto d:dir){
                        if(!valid(x+d.first,y+d.second)) continue;
                        st.push({x+d.first,y+d.second});
                    }
                }
            }
        }
        return num;
    }
};
