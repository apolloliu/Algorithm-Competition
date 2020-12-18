/***
方法一：动态规划，时间复杂度为O(n) 空间复杂度为O(n)，状态转移方程为
dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2];
--------这里必须保证i-1和i-dp[i-1]-2有意义
****/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>dp(n, 0);
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')continue;
            int j = i - 1, tmp = 0;
            if(j >= 0)tmp = dp[j];
            if(i - tmp - 1 >= 0 && s[i - tmp - 1] == '('){
                dp[i] = tmp + 2;
                if(i - tmp - 2 >= 0)dp[i] += dp[i - tmp - 2];
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

//方法二：从前往后，将字符串分割成几段，每一段要满足：除了最后一个字符，之前的字符都是有效括号匹配字符
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        stack<int>St;
        while(St.size())St.pop();
        for(int i = 0, id = -1; i < n; ++i){
            if(s[i] == '(')St.push(i);
            else {
                if(St.size()){
                    res = max(res, i - St.top() + 1);
                    St.pop();
                    if(!St.size())res = max(res, i - id);
                    else res = max(res, i - St.top());
                }
                else id = i;
            }
        }
        return res;
    }
};

// 方法三：从后往前做
class Solution {
public:
    int longestValidParentheses(string s){
        int n = s.size();
        stack<int>St;
        while(!St.empty())St.pop();
        int res = 0, id = n;
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == ')'){
                St.push(i);
            }
            else if(s[i] == '('){
                if(St.size()){
                    res = max(res, St.top() - i);
                    St.pop();
                    if(St.size())res = max(res, St.top() - i);
                    else res = max(res, id - i);
                }
                else id = i;
            }
        }
        return res;
    }
};
