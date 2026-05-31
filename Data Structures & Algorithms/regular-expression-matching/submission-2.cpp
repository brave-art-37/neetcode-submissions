class Solution {
public:

    string s,p;
    vector<vector<int>> dp;

    bool recurr(int i, int j){
        if(i==s.size() && j==p.size()) return true;
        else if(i>s.size() || j>=p.size()) return false;
        else if(dp[i][j]!=-1) return (bool) dp[i][j];

        bool val = 0;
        if(j+1<p.size() && p[j+1]=='*'){ //"x*"
            val |= ((s[i]==p[j]) || (p[j]=='.')) && recurr(i+1,j); //not skip
            val |= recurr(i,j+2); //skip
        }
        else{ //"x"
            val |= ((s[i]==p[j]) || (p[j]=='.')) && recurr(i+1,j+1);
        }
        dp[i][j] = val;
        return val;
    }

    bool isMatch(string _s, string _p) {
        s = _s, p = _p;
        dp = vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
        return recurr(0,0);
    }
};