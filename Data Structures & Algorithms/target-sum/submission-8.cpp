class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<map<int,int>> dp(n);
        dp[0][-nums[0]] += 1;
        dp[0][nums[0]] += 1;
        for(int i=1;i<n;i++){
            for(auto& [amt,ways]:dp[i-1]){
                dp[i][amt-nums[i]] += ways;
                dp[i][amt+nums[i]] += ways;
            }
        }
        if(!dp[n-1].count(target)) return 0;
        return dp[n-1][target];
    }
};
