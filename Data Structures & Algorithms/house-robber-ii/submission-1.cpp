class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp(2,vector<int>(nums.size())); //dp[0][k] -> did NOT rob first house
        dp[1][0] = nums[0];
        dp[0][1] = nums[1]; dp[1][1] = nums[0];
        for(int k=2;k<nums.size();k++){
            dp[0][k] = max(dp[0][k-1], dp[0][k-2]+nums[k]);
            if(k==nums.size()-1) dp[1][k] = max(dp[1][k-1],dp[1][k-2]); //can't rob both first & last house
            else dp[1][k] = max(dp[1][k-1], dp[1][k-2]+nums[k]);
        }
        return max(dp[0][nums.size()-1], dp[1][nums.size()-1]);
    }
};
