class Solution {
public:
    bool check(vector<int> &need, vector<int> &have){
        bool works=1;
        for(int i=0;i<26;i++){
            works&=(need[i]==have[i]);
        }
        return works;
    }
    bool checkInclusion(string s1, string s2) {
        bool ans=false;
        if(s2.size()<s1.size()) return ans;
        vector<int> need(26);
        for(char c:s1) need[c-'a']++;
        vector<int> have(26);
        for(int i=0;i<s1.size();i++){
            have[s2[i]-'a']++;
        }
        ans|=check(need,have);
        if(ans) return ans;
        for(int i=s1.size();i<s2.size();i++){
            have[s2[i]-'a']++;
            have[s2[i-s1.size()]-'a']--;
            ans|=check(need,have);
            if(ans) return ans;
        }
        return ans;
    }
};