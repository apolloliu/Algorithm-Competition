// 利用滑动窗口，窗口大小为m*w，一直记录出现的有效元素个数（有效元素值在words出现的，且不超过words每一类单词数的元素个数），达到words的个数即求得解
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        res.clear();
        if(!words.size())return res;
        unordered_map<string, int>wc;
        int f = 0;
        wc.clear();
        int n = s.size(), w = words.size(), m = words[0].size();
        for(string st: words)wc[st] ++;
        cout << n << endl;
        for(int i = 0; i < m; ++i){
            unordered_map<string, int>cnt;
            int count = 0;
            for(int j = i; j + m - 1 < n; j += m){
                string tmp = s.substr(j, m);
                // if(!wc[tmp]){cnt.clear(); count = 0; continue;}  这里不能把原来的记录清楚，因为这样就不是固定滑动窗口了
                
                cnt[tmp]++;
                if(cnt[tmp] <= wc[tmp])count++;
                if(j + m - i >= m*w){
                    if(count == w)res.push_back(j - (w-1)*m);
                    string tmp = s.substr(j - (w-1)*m, m);
                    cnt[tmp]--;
                    if(cnt[tmp] < wc[tmp])count --;
                }
            }
        }
        return res;
    }
};
