// 将每个字符串排序，放到一个hash表里，hash表每个元素就是一个满足要求的字符串集合，时间复杂度O(NlogM)，M为最长字符串长度
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>res;
        if(!n)return res;
        unordered_map<string, vector<string>>hash;
        for(int i = 0; i < n; ++i){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(strs[i]);
        }
        for(auto& x: hash)res.push_back(x.second);
        return res;
    }
};
