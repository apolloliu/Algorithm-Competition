
// 从第一字符开始扫，不满足即返回，最大复杂度为所有字符串的长度和
// 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())return "";
        int n = strs.size();
        bool flag = true;
        string s;
        for(int len = strs[0].size(); len; --len){
            flag = true;
            s = strs[0].substr(0, len);
            for(int i = 1; i < n; ++i){
                if(strs[i].substr(0, len) != s){flag = false; break;}
            }
            if(flag)return s;
        }
        return "";
    }
};
