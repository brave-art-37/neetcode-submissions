class Solution {
public:
    void recurr(vector<int>& nums, int i, int target, vector<vector<int>>& ans, vector<int>& sub){
        if(target==0) ans.push_back(sub);
        if(target<nums[0] || i<0) return;

        if(target>=nums[i]){
            sub.push_back(nums[i]);
            recurr(nums,i,target-nums[i],ans,sub);
            sub.erase(sub.end());
        }
        recurr(nums,i-1,target,ans,sub);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        recurr(nums,nums.size()-1,target,ans,sub);
        return ans;
    }
};
