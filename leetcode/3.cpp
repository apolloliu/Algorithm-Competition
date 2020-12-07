class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")return 0;
        unordered_map<char, int>mp;
        mp.clear();
        int n = s.size();
        int res = 0;
        int len = 0;
        for(int i = 0; i < n; ++i){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
                len++;
            }
            else {
                res = max(res, len);
                if(i - mp[s[i]] <= len)len = i - mp[s[i]];
                else len++;
                mp[s[i]] = i;
            }
        }
        res = max(res, len);
        return res;
    }
};
