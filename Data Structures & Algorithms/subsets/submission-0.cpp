class Solution {
public:
    void recurr(int r, vector<int>& nums, vector<int>& sub, vector<vector<int>>& ans){
        if(r==nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[r]);
        recurr(r+1, nums, sub, ans);
        sub.erase(sub.end());
        recurr(r+1, nums, sub, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        recurr(0, nums, sub, ans);
        return ans;
    }
};
