//10. Regular Expression Matching
// DP
//
class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        if(N == 2 && p[0] == '.' && p[1] == '*')return true;
        vector<vector<bool>>dp(M+1, vector<bool>(N+1, false));
        dp[M][N] = true;
        for(int i = M; i >= 0; --i){
            for(int j = N; j >= 0; --j){
                bool ismatch = i < M && (s[i] == p[j] || p[j] == '.');
                //if(j + 1 < N && p[j+1] == '*' && p[j] == '.')return true;
                if(j + 1 < N && p[j+1] == '*')dp[i][j] = ismatch && dp[i+1][j] || dp[i][j+2];
                else if(i < M && j < N)dp[i][j] = ismatch && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, 0));
        s = ' ' + s; p = ' ' + p;
        dp[0][0] = 1;
        
        for(int i = 0; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(j+1 < m && p[j+1] == '*')continue;  // A*中A不能单独算，要将A*看做整体
                if(p[j] == s[i] || p[j] == '.' && i){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j] == '*'){
                    dp[i][j] = j >= 2 && dp[i][j-2] || i && dp[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.');
                }
            }
        }

        return dp[n][m];
    }
};
