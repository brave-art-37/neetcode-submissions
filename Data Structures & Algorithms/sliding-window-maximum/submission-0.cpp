class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(!q.empty() && q.back().first<nums[i]) q.pop_back();
            q.push_back({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(q.front().first);
        for(int i=k;i<n;i++){
            int idx=q.front().second;
            if(i-idx>=k) q.pop_front();
            while(!q.empty() && q.back().first<nums[i]) q.pop_back();
            q.push_back({nums[i],i});
            ans.push_back(q.front().first);
        }
        return ans;
    }
};
