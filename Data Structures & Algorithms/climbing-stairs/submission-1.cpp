class Solution {
public:

    int climbStairs(int n) {
        vector<int> dp(46);
        dp[1]=1, dp[2]=2;
        for(int k=3;k<46;k++){
            dp[k] = dp[k-1]+dp[k-2];
        }
        return dp[n];
    }
};
