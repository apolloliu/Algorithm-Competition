// 深搜，但是要注意，'('和')'的数量一样，并且是有效的
class Solution {
public:
    vector<string> res;
    void dfs(int cur, int n, string s, int L, int R){
        if(cur == n*2){if(L == R)res.push_back(s); return;}
        for(auto x: "()"){
            if(x == ')' && L < 1 + R)continue;
            if(x == ')')dfs(cur+1, n, s+x, L, R+1);
            else if(x == '(')dfs(cur+1, n, s+x, L+1, R);
        }
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(0, n, "", 0, 0);
        return res;
    }
};
