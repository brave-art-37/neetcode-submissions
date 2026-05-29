class Solution {
public:
    string s, t;
    vector<vector<int>> dp;
    int recurr(int i, int j){
        if(i==s.size() || j==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j]=1+recurr(i+1,j+1);
        else return dp[i][j]=max(recurr(i,j+1), recurr(i+1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        s = text1; t = text2;
        dp = vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
        return recurr(0, 0);
    }
};