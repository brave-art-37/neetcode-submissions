class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        if(n==1) return 0;

        vector<vector<int>> dp(2,vector<int>(n));
        //max profit - dp[0(1)][k] sold(buy) at day k
        dp[0][0] = 0, dp[1][0] = -p[0];
        dp[0][1] = max(0,p[1]-p[0]), dp[1][1] = max(-p[1],-p[0]);
        for(int i=2;i<n;i++){
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]+p[i]);
            dp[1][i] = max(dp[0][i-2]-p[i], dp[1][i-1]);
            //first term cause only allowed to buy if sold <=(i-2)
        }
        /*
        cout<<"dp:\n";
        for(int i=0;i<n;i++) cout<<dp[0][i]<<' ';cout<<"\n";
        for(int i=0;i<n;i++) cout<<dp[1][i]<<' ';cout<<"\n";
        */
        return dp[0][n-1];
    }
};