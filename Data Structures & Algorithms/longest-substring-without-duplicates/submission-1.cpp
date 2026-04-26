class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastUsed(128,-1);
        int ans=0, nodup=-1;
        for(int i=0;i<s.size();i++){
            nodup=max(nodup,lastUsed[s[i]]);
            ans=max(ans,i-nodup);
            lastUsed[s[i]]=i;
        }
        return ans;
    }
};
