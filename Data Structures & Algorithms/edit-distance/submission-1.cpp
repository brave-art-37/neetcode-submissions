class Solution {
public:
    string s,t;
    vector<vector<int>> dp;
    int recurr(int i, int j){
        if(j==t.size()) return (s.size()-i); //rem rest from s
        else if(i==s.size()) return (t.size()-j); //add rest to s
        else if(dp[i][j]!=-1) return dp[i][j];

        int val = INT_MAX/2;
        val = min(val, (s[i]!=t[j])+recurr(i+1,j+1)); //replace in s
        val = min(val, 1+recurr(i,j+1)); //add to s
        val = min(val, 1+recurr(i+1,j)); //del in s
        dp[i][j] = val;
        return val;
    }

    int minDistance(string word1, string word2) {
        s=word1, t=word2;
        dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1,-1));
        return recurr(0,0);
    }
};