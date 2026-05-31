class Solution {
public:
    int minDistance(string word1, string word2) {
        string s=word1, t=word2;
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1));
        //dp[i][j] = min ops to make s[i:] = t[j:]
        for(int i=s.size();i>-1;i--){
            for(int j=t.size();j>-1;j--){
                if(i==s.size()) dp[i][j] = (t.size()-j); //add rest from t to s
                else if(j==t.size()) dp[i][j] = (s.size()-i); //del rest from s
                else{
                    dp[i][j] = min({
                        (s[i]!=t[j])+dp[i+1][j+1], //replace in s
                        1+dp[i][j+1], //add in s
                        1+dp[i+1][j] //del in s
                    });
                }
            }
        }
        return dp[0][0];
    }
};