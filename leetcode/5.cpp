// O(n^2)
// 确定中间位置，然后往两边扫
// 运行时间：32 ms  内存消耗: 14.4 MB
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string fs = "";
        int len, l, r, flag;
        for(int i = 0; i < n; ++i){
            len = 1, l = i, r = i, flag = false;
            while(l >= 0 && r < n && s[l] == s[r]){l--;r++; flag = true;}
            if(flag && r-l-1 32 ms> fs.size())fs = s.substr(l+1, r-l-1);
            len = 1, l = i, r = i + 1, flag = false;
            while(l >= 0 && r < n && s[l] == s[r]){l--;r++; flag = true;}
            if(flag && r-l-1 > fs.size())fs = s.substr(l+1, r-l-1);
        }
        return fs;
    }
};

// O(n^2) 动态规划
// 运行时间：1636 ms	内存消耗：47.1 MB
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // s = ' ' + s;
        vector<vector<bool>>dp(n, vector<bool>(n, 0));
        for(int i = 0; i < n; ++i)dp[i][i] = 1;
        int id = 0;
        string fs = "";
        for(int len = 1; len <= n; ++len){
            for(int i = 0; i + len - 1 < n; ++i){
                int j = i + len - 1;
                if(len <= 2)dp[i][j] = s[i] == s[j];
                else if(s[i] == s[j])dp[i][j] = dp[i+1][j-1];
                if(dp[i][j] && len > fs.size()){
                    fs = s.substr(i, len);
                }
            }
        }
        
        return fs;
    }
};
