class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> v={nums[i],nums[j],nums[k]};
                    ans.insert(v);
                    j++,k--;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        vector<vector<int>> unique;
        for(auto p:ans) unique.push_back(p);
        return unique;
    }
};
