class Solution {
public:
    int n;
    int firstTrue(int lo, int hi, function<bool(int)> f){
        int ans=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(mid)) ans=mid, hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
    bool valid(int x, int y){
        return (x>-1 && x<n)&&(y>-1 && y<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        return firstTrue(grid[0][0],n*n-1,[&](int k){
            stack<pair<int,int>> st;
            vector<vector<int>> vis(n,vector<int>(n));
            st.push({0,0});
            while(!st.empty()){
                auto [x,y] = st.top();st.pop();
                if(x==n-1 && y==n-1) return true;
                vis[x][y]=1;
                for(auto d:dir){
                    int x1=x+d.first, y1=y+d.second;
                    if(valid(x1, y1) && !vis[x1][y1] && grid[x1][y1]<=k) st.push({x1,y1});
                }
            }
            return false;
        });
    }
};