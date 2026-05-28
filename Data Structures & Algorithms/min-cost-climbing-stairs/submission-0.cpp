class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,INT_MAX);
        dp[0]=0, dp[1]=0;
        for(int k=2;k<cost.size()+1;k++){
            dp[k] = min(dp[k], dp[k-2]+cost[k-2]);
            dp[k] = min(dp[k], dp[k-1]+cost[k-1]);
        }
        return dp[cost.size()];
    }
};
