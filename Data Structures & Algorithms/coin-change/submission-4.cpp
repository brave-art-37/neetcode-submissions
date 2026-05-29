class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        sort(coins.begin(),coins.end());
        vector<bool> dp(amount+1,0), tmp(amount+1,0); //dp[amt] ie amt taken
        dp[0]=1;tmp[0]=1;

        //for(int i=0;i<amount+1;i++) cout<<i<<' ';cout<<"\n";

        for(int k=1;k<amount+1;k++){
            for(int amt=0;amt<amount+1;amt++){
                if(!dp[amt]) continue; //can't form yet
                for(int num:coins){
                    if(amt>amount-num) break;
                    tmp[amt+num] = 1; //don't affect curr round
                }
            }
            for(int amt=0;amt<amount+1;amt++) dp[amt] = tmp[amt];
            //cout<<k<<":\n";for(int num:dp) cout<<num<<' ';cout<<"\n";
            if(dp[amount]) return k;
        }
        return -1;
    }
};