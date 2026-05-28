class Solution {
public:
    int n;
    int cnt(string& s, int l, int r){
        int res=0;
        while(l>-1 && r<n){
            if(s[l]!=s[r]) break;
            res++, l--, r++;
        }
        return res;
    }
    int countSubstrings(string s) {
        n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            res+=cnt(s,i,i);
            if(i+1<n) res+=cnt(s,i,i+1);
        }
        return res;
    }
};
