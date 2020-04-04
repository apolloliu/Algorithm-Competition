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

