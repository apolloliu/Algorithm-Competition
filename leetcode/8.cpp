class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        long long res = 0;
        bool flag = false;
        while(s[i] == ' ')++i;
        if(i == n || s[i] != '+' && s[i] != '-' && (s[i] < '0' || s[i] > '9'))return 0;
        if(s[i] == '-')flag = true, i++;
        else if(s[i] == '+')i++;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            res *= 10;
            res += s[i] - '0';
            ++i;
            if(flag && -res < INT_MIN)return INT_MIN;
            else if(!flag && res > INT_MAX)return INT_MAX;
        }
        return flag ? -res : res;
    }
};
