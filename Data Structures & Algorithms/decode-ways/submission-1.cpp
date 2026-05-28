class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    int recurr(int k){//decomp s[k...]
        if(k>=n-1) return 1;
        else if(dp[k]!=-1) return dp[k];
        else if(s[k]=='0') return dp[k]=0;
        else if(s[k]=='1'){
            dp[k] = recurr(k+2);
            if(s[k+1]!='0') dp[k]+=recurr(k+1);
        }
        else if(s[k]=='2'){
            if(s[k+1]=='0') dp[k]=recurr(k+2);
            else if(s[k+1]-'0' < 7) dp[k]=recurr(k+1)+recurr(k+2);
            else dp[k]=recurr(k+1);
        }
        else{
            if(s[k+1]=='0') return 0; //invalid config
            dp[k] = recurr(k+1);
        }
        return dp[k];
    }

    int numDecodings(string t) {
        if(t=="0") return 0;
        s=t, n=t.size();
        dp = vector<int>(n,-1);
        return recurr(0);
    }
};