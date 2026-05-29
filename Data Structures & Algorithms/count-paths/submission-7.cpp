class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        long double res=1;
        m--, n--;
        for(long double k=0;k<n;k++){
            res = res*(m+n-k)/(n-k);
        }
        return res;
        */
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};