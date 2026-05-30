class Solution {
public:
    vector<vector<int>> dp;
    string s1, s2, s3;
    int recurr(int i, int j){
        if(i==s1.size() && j==s2.size()) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = 0;
        if(i<s1.size() && s1[i]==s3[i+j]) dp[i][j]|=recurr(i+1,j);
        if(j<s2.size() && s2[j]==s3[i+j]) dp[i][j]|=recurr(i,j+1);
        return dp[i][j];
    }

    bool isInterleave(string t1, string t2, string t3) {
        s1=t1, s2=t2, s3=t3;
        dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1,-1));
        if(s3.size()!=s1.size()+s2.size()) return false;
        return recurr(0,0);
    }
};