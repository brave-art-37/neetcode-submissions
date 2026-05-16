class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> res;
    vector<string> sub;

    //decide for palindromic substr start at idx
    void recurr(string s, int idx){
        if(idx==s.size()) {
            res.push_back(sub);
            return;
        }
        for(int j=idx;j<s.size();j++){
            if(!dp[idx][j]) continue; //not palindromic substr
            sub.push_back(s.substr(idx,j-idx+1));
            recurr(s,j+1);
            sub.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp = vector<vector<bool>>(n,vector<bool>(n));
        for(int len=1;len<=n;len++){
            for(int st=0;st+len-1<n;st++){
                if(len==1) dp[st][st]=1;
                else if(len==2) dp[st][st+1] = (s[st]==s[st+1]);
                else dp[st][st+len-1] = dp[st+1][st+len-2]&&(s[st]==s[st+len-1]);
            }
        }
        recurr(s,0);
        return res;
    }
};
