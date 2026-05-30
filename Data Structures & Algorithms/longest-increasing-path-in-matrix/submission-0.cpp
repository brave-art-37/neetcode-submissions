class Solution {
public:
    int m,n;
    vector<vector<int>> dp, mat;
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    int valid(int x, int y){
        return (x>-1 && x<m)&&(y>-1 && y<n);
    }

    int recurr(int x, int y){
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y] = 1;
        for(auto d:dir){
            int x1=x+d.first, y1=y+d.second;
            if(!valid(x1,y1) || mat[x1][y1]<=mat[x][y]) continue;
            dp[x][y] = max(dp[x][y], 1+recurr(x1,y1));
        }
        return dp[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        mat = matrix;
        m = matrix.size(), n=matrix[0].size();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi = max(maxi,recurr(i,j));
            }
        }
        return maxi;
    }
};