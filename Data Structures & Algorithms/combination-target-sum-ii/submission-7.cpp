class Solution {
public:
    vector<vector<int>> res;
    vector<int> sub;
    void recurr(vector<int>& nums, int target, int idx){
        if(idx==nums.size() || target<=0){
            if(target==0) res.push_back(sub);
            return;
        }
        sub.push_back(nums[idx]); //using at least 1 nums[idx]
        recurr(nums,target-nums[idx],idx+1); //each idx max once
        sub.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++; //skip all duplicates
        recurr(nums,target,idx+1);

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        recurr(nums,target,0);
        return res;
    }
};
