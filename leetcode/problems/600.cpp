class Solution {
public:
    int findIntegers(int num) {
        int n = num;
        vector<int>v;
        v.clear();
        while(n)v.push_back(n%2), n/=2;
        int m = v.size();
        vector<vector<int>>dp(m+1, vector<int>(2, 0));
        int last = 0;
        dp[1][0] = dp[1][1] = 1;
        for(int i = 2; i <= m; ++i){
            dp[i][0] = dp[i-1][1] + dp[i-1][0];
            dp[i][1] = dp[i-1][0];
        }
        int res = 0;
        for(int i = m-1; i >= 0; --i){
            if(v[i]){
                res += dp[i+1][0];
                if(last)return res;
            }
            last = v[i];
        }
        return res+1;
    }
};
