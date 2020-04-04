//62. Unique Paths
// DP

class Solution {
public:
    int dp[110][110];
    int uniquePaths(int m, int n) {
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        //for(int i = 0; i < m; ++i)dp[0][i] = 1;
        for(int i = 0; i <= n; ++i){
           for(int j = 0; j <= m; ++j){
               int ans = 0;
               if(i>0 && dp[i-1][j])dp[i][j] += dp[i-1][j];
               if(j>0 && dp[i][j-1])dp[i][j] += dp[i][j-1];
           }
       }
       return dp[n][m];
    }
};
