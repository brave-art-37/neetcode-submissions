class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX/2);
        dp.back()=0;
        for(int i=nums.size()-2;i>-1;i--){
            if(i+nums[i]>=nums.size()-1) dp[i]=1;
            else{
                for(int j=i+1;j<min(i+nums[i]+1,(int)nums.size());j++){
                    dp[i] = min(dp[i], 1+dp[j]);
                }
            }
        }
        return dp[0];
    }
};