//343. Integer Break
//DP

class Solution {
public:
    int integerBreak(int n) {
        int dp[60];
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = max(dp[i], i-1);
            for(int j = 1; j < i; ++j){
                dp[i] = max(dp[i], dp[j]*(i-j));
                dp[i] = max(dp[i], j*(i-j));
            }
        }
        return dp[n];
    }
};
