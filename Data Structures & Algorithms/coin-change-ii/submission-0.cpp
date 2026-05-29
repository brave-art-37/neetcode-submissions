class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        //dp[amt] = #ways to for amt
        for(int num:coins){
            for(int amt=0;amt<amount+1-num;amt++){
                dp[amt+num] += dp[amt];
            }
        }
        return dp[amount];
    }
};
