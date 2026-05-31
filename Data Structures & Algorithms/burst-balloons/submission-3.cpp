class Solution {
public:

    int n;
    vector<vector<int>> dp;

    int recurr(vector<int>& nums, int i, int j){
        if(j<i) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 0;
        for(int k=i;k<=j;k++){
            int val = nums[i-1]*nums[k]*nums[j+1];
            val += recurr(nums,i,k-1) + recurr(nums,k+1,j);
            maxi = max(maxi, val);
        }
        dp[i][j] = maxi;

        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        nums.insert(nums.begin(),1);nums.push_back(1);
        dp = vector<vector<int>>(n+2,vector<int>(n+2,-1));
        return recurr(nums,1,n);
    }
};