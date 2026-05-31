class Solution {
public:
    vector<vector<int>> dp;
    map<char,vector<int>> idx;
    string s,t;

    int recurr(int i, int j){ //find t[j] in s after idx i
        if(j >= t.size()) return 1;
        else if(j<t.size() && i>=s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        char c=t[j];
        if(!idx.count(c)) return 0;
        auto it = lower_bound(idx[c].begin(), idx[c].end(), i);
        if(it==idx[c].end()) return 0;
        dp[i][j] = 0;
        for(auto tmp=(it-idx[c].begin());tmp<idx[c].size();tmp++){
            if(idx[c][tmp]+1 > s.size()) break;
            dp[idx[c][tmp]+1][j+1] = recurr(idx[c][tmp]+1,j+1);
            dp[i][j] += dp[idx[c][tmp]+1][j+1];
        }
        return dp[i][j];
    }

    int numDistinct(string _s, string _t) {
        s = _s, t=_t;
        dp = vector<vector<int>>(s.size()+1,vector<int>(t.size()+1,-1));
        for(int i=0;i<s.size();i++) idx[s[i]].push_back(i);
        return recurr(0,0);
    }
};