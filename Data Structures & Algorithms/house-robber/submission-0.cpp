class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(2,vector<int>(nums.size())); //dp[0][k] -> NOT chosen
        dp[1][0] = nums[0];
        for(int k=1;k<nums.size();k++){
            dp[0][k] = max(dp[0][k-1],dp[1][k-1]);
            dp[1][k] = nums[k] + dp[0][k-1];
        }
        return max(dp[0][nums.size()-1],dp[1][nums.size()-1]);
    }
};