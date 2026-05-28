class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> valid(n,vector<bool>(n));
        vector<vector<int>> dp(n,vector<int>(n));
        for(int len=1;len<=n;len++){
            for(int l=0;l<n-len+1;l++){
                int r=l+len-1;
                if(len==1) valid[l][r]=1, dp[l][r]=1;
                else if(len==2) valid[l][r]=(s[l]==s[r]), dp[l][r]=2+valid[l][r];
                else{
                    valid[l][r] = valid[l+1][r-1]&(s[l]==s[r]);
                    dp[l][r]=dp[l+1][r-1]+valid[l][r];
                    for(int k=l;k<r;k++) dp[l][r]+=valid[l][k]+valid[k+1][r];
                }
            }
        }
        return dp[0][n-1];
    }
};