//63. Unique Paths II
//DP

class Solution {
public:
    long long dp[110][110];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, 0, sizeof(dp));
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(!obstacleGrid[0][0])dp[1][1] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(obstacleGrid[i-1][j-1])continue;
                dp[i][j] += dp[i][j-1];
                dp[i][j] += dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
