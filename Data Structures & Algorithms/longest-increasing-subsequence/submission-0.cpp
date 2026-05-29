class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> piles;
        unordered_map<int,int> pre;
        for(int num:nums){
            if(piles.empty()){
                piles.push_back(num);
                continue;
            }
            auto it = lower_bound(piles.begin(),piles.end(),num);
            if(it==piles.end()){
                pre[num] = piles.back();
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