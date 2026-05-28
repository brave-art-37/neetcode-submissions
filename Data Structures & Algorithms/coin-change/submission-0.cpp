class Solution {
public:
    vector<int> coins;

    int recurr(int idx, int amt){
        if(amt==0) return 0;
        else if(amt<coins[0]) return INT_MAX/2;
        int res=INT_MAX/2;
        for(int i=0;i<=idx;i++){
            if(coins[i]>amt) break;
            res = min(res, 1+recurr(i,amt-coins[i])); //as if i<j, choosing i before j will double count
        }
        return res;
    }
    int coinChange(vector<int>& _coins, int amt) {
        coins = _coins;
        sort(coins.begin(),coins.end());
        int res=recurr(coins.size()-1, amt);
        return (res==INT_MAX/2)?-1:res;
    }
};