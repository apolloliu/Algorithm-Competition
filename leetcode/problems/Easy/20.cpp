// O(n) 栈的对应
class Solution {
public:
    bool isValid(string s) {
        if(!s.size())return true;
        int i = 0;
        stack<char>T;
        while(!T.empty())T.pop();
        while(i < s.size()){
            if(s[i] == '['  || s[i] == '{' || s[i] == '(')T.push(s[i]);
            else {
                if(T.empty())return false;
                if(s[i] == '}' && T.top() != '{')return false;
                else if(s[i] == ')' && T.top() != '(')return false;
                else if(s[i] == ']' && T.top() != '[')return false;
                else T.pop();
            }
            i++;
        }
        if(T.empty())return true;
        else return false;
    }
};
