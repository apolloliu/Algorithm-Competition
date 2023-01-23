// 暴力搜索
string arr[10] = {"@","@","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string>res;
    void dfs(int n, string s, string tmp){
        if(n == s.size()){res.push_back(tmp); return;}
        int c = s[n] - '0';
        for(char ch: arr[c]){
            dfs(n+1, s, tmp+ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(!digits.size())return res;
        dfs(0, digits, "");
        return res;
    }
};
