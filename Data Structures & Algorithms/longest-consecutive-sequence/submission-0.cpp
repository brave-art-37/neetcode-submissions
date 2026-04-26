class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> elts;
        int maxi=0;
        for(int n:nums) elts[n]=1; //avail for chain extend
        for(auto &p:elts){
            int len=1;
            int num=p.first;p.second=0;
            while(elts.count(num+1)!=0){
                elts[num+1]=0;
                num++; len++;
            }
            maxi=max(maxi,len);
        }
        return maxi;
    }
};