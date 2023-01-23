//方法一：KMP算法，时间复杂度O(n), 空间复杂度O(m)
class Solution{
public:
    int strStr(string s, string p){
        int n = s.size(), m = p.size();
        if(!m)return 0;
        s = ' ' + s;
        p = ' ' + p;
        vector<int>next(m+1);
        for(int i = 2, j = 0; i <= m; i++){
            while(j && p[i] != p[j+1])j = next[j];
            if(p[i] == p[j+1])j++;
            next[i] = j;
        }

        for(int i = 1, j = 0; i <= n; i++){
            while(j && s[i] != p[j+1])j = next[j];
            if(s[i] == p[j+1])j++;
            if(j == m)return i - m;
        }
        return -1;
    }
};

// 方法二：用暴力，时间复杂度O(nm)，空间复杂度O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(!m)return 0;
        if(n < m)return -1;
        for(int i = 0; i + m - 1 < n; ++i){
            bool eq = true;
            for(int j = 0; j < m; ++j)if(haystack[i+j] != needle[j]){eq = false; break;}
            if(eq)return i;
        }
        return -1;
    }
};

// //方法三：滑动窗口，时间复杂度O(n)，空间复杂度O(m)
class Solution {
public:
    int strStr(string h, string ne){
        int n = h.size(), m = ne.size();
        if(!m)return 0;
        if(!n)return -1;
        if(n < m)return -1;
        unordered_map<char, int>wd;
        for(char c: ne)wd[c]++;
        
        for(int i = 0; i < m; ++i){
            unordered_map<char, int>cnt;
            int count = 0;
            for(int j = i; j + m - 1 < n; j ++){
                char c = h[i];
                cnt[c]++;
                if(cnt[c] <= wd[c])count++;
                if(j - i + 1 >= m){
                    if(count == m){cout << j - m + 1 << endl; return j - m + 1;}
                    char c1 = h[j-m+1];
                    cnt[c1] --;
                    if(cnt[c1] < wd[c1])count--;
                }
            }
        }
        return -1;
    }
};
