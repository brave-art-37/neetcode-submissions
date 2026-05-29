class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, minProd=1, maxProd=1;
        for(int num:nums){
            int maxProdNew = max({maxProd*num, minProd*num, num});
            int minProdNew = min({maxProd*num, minProd*num, num});
            maxProd = maxProdNew;
            minProd = minProdNew;
            res = max(res,maxProd);
        }
        return res;
    }
};
