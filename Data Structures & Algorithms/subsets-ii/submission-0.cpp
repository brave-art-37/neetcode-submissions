class Solution {
public:
    vector<vector<int>> res;
    vector<int> sub;
    void recurr(vector<int>& nums, int idx){
        if(idx==nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[idx]);
        recurr(nums,idx+1);
        sub.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
        recurr(nums,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recurr(nums,0);
        return res;
    }
};
