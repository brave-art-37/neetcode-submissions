class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> piles;
        unordered_map<int,int> pre;
        //patience sort
        for(int num:nums){
            auto it = lower_bound(piles.begin(),piles.end(),num);
            if(it==piles.end()){
                if(!piles.empty()) pre[num] = piles.back();
                piles.push_back(num);
            }
            else{
                piles[it-piles.begin()] = num;
                if(it!=piles.begin()) pre[num] = piles[it-piles.begin() -1];
            }
        }
        return piles.size();
    }
};