class Solution {
public:
    vector<vector<int>> dp;
    string s,t;

    int recurr(int i, int j){
        if(j>=t.size()) return 1;
        else if(j<t.size() && i > s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = recurr(i+1,j) + ((s[i]==t[j])?recurr(i+1,j+1):0);

    }
    int numDistinct(string _s, string _t) {
        s = _s, t = _t;
        dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1,-1));
        return recurr(0,0);
    }
};