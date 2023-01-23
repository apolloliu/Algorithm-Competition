// 区间DP，dp[i][j] 表示先手对后手的最大差值
class Solution {
public:
    int stoneGameVII(vector<int>& s) {
        int n = s.size();
        vector<int>sum(n+1, 0);
        for(int i = 1; i <= n; ++i)sum[i] = sum[i-1] + s[i-1];
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int len = 2; len <= n; ++len){
            for(int i = 1; i + len - 1 <= n; ++i){
                int j = i + len - 1;
                dp[i][j] = max(sum[j] - sum[i] - dp[i+1][j], sum[j-1] - sum[i-1] - dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};
