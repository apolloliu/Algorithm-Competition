//72. Edit Distance
//DP

class Solution {
public:
    const int inf = 0x7f7f7f7f;
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>>dp(s1+1, vector<int>(s2+1, inf));
        if(!s1 || !s2)return max(s1, s2);
        dp[0][0] = 0; //dp[0][1] = 1; dp[1][0] = 1;
        for(int i = 0; i < s1; ++i)dp[i][0] = i;
        for(int j = 0; j < s2; ++j)dp[0][j] = j;
        for(int i = 0; i < s1; ++i){
            for(int j = 0; j < s2; ++j){
                if(word1[i] == word2[j])dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                else {
                    int ans = inf;
                    ans= min(ans, dp[i+1][j]+1);
                    ans = min(ans, dp[i][j+1]+1);
                    ans = min(ans, dp[i][j]+1);
                    dp[i+1][j+1] = min(dp[i+1][j+1], ans);
                }
            }
        }
        return dp[s1][s2];
    }
};
