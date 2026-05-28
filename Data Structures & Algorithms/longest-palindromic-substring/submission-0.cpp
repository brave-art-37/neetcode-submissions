class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> valid(n,vector<bool>(n));
        //valid[l][r] if [l...r] is palindrome
        string lng = "";
        for(int len=1;len<=n;len++){
            for(int l=0;l<n-len+1;l++){
                int r=l+len-1;
                if(len==1) valid[l][r]=true; //single char
                else if(len==2) valid[l][r]=(s[l]==s[r]); //couple
                else valid[l][r] = valid[l+1][r-1]&(s[l]==s[r]);
                
                if(valid[l][r] && len>lng.size()) lng = s.substr(l,len);
            }
        }
        return lng;
    }
};