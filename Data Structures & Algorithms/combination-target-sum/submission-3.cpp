class Solution {
public:
    vector<vector<int>> res;
    vector<int> sub;
    void recurr(vector<int>& nums, int target, int idx){
        if(idx==nums.size() || target<=0){
            if(target==0) res.push_back(sub);
            return;
        }
        sub.push_back(nums[idx]); //use nums[idx]
        recurr(nums,target-nums[idx],idx); //since can repeat
        sub.pop_back();
        recurr(nums,target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        recurr(nums,target,0);
        return res;
    }
};
