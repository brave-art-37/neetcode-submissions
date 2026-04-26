class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> maxlen(26);
        for(int i=0;i<26;i++){
            char c=(char)(i+'A');
            int replace=0;
            int l=0;
            for(int r=0;r<s.size();r++){
                replace+=(s[r]!=c);//extend
                while(l<r && replace>k) replace-=(s[l]!=c), l++;//shrink
                if(replace<=k) maxlen[i]=max(maxlen[i],r-l+1); //within k changes
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++) ans=max(ans,maxlen[i]);
        return ans;
    }
};
