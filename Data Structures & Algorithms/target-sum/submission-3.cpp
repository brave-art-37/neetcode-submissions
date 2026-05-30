class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        dp[0][-nums[0]] += 1;
        dp[0][nums[0]] += 1;
        for(int i=1;i<nums.size();i++){
            for(auto [amt,ways]:dp[i-1]){
                dp[i][amt-nums[i]] += ways;
                dp[i][amt+nums[i]] += ways;
            }
        }
        if(!dp[nums.size()-1].count(target)) return 0;
        return dp[nums.size()-1][target];
    }
};
