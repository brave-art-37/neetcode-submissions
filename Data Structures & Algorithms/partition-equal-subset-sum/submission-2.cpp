class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%2==1) return false;

        vector<bool> dp(sum+1), tmp(sum+1);
        dp[0]=true, tmp[0]=false;
        for(int num:nums){
            for(int i=0;i<sum+1-num;i++){
                if(!dp[i]) continue;
                tmp[i+num] = 1;
            }
            for(int i=0;i<sum+1;i++) dp[i] = tmp[i];
        }
        /*
        cout<<"dp:\n";
        for(int num:dp) cout<<num<<' ';cout<<"\n";
        */
        return dp[sum/2];
    }
};