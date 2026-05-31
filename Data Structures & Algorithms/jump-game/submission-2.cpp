class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> vis(nums.size());
        vis.back()=1;
        int last = nums.size()-1;
        for(int i=nums.size()-2;i>-1;i--){
            if(i+nums[i]>=last) vis[i] = 1, last = i;
        }
        return vis[0];
    }
};