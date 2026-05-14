class Solution {
public:
    void recurr(vector<vector<int>>& ans, vector<int>& sub, vector<int>& nums, int idx){
        cout<<"idx="<<idx<<", sub=";for(int num:sub) cout<<num<<' ';cout<<"\n";
        if(idx==nums.size()) {
            ans.push_back(sub);
            return;
        }
        for(int i=0;i<idx+1;i++){
            sub.insert(sub.begin()+i,nums[idx]);
            recurr(ans,sub,nums,idx+1);
            sub.erase(sub.begin()+i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sub.push_back(nums[0]);
        recurr(ans,sub,nums,1);
        return ans;
    }
};
