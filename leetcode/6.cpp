// method 1
// O(n)时间 O(n)空间
class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int n = s.size();
        if(numRows == 1)return s;
        vector<string>v(numRows);
        int i = 0, t = 0;
        bool flag = true; // flag = True means t increases, False means t decreases.
        while(i < n){
            v[t] += s[i];
            i++;
            if(flag)++t;
            else --t;
            if(t == 0)flag = true;
            if(t == numRows-1)flag = false;
        }
        for(auto x: v)res += x;
        return res;
    }
};


// method 2
// O(nlogn) O(logn)空间
typedef pair<int, int> pii;
class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int n = s.size();
        if(numRows == 1)return s;
        vector<pii>v(n);
        int i = 0, t = 0;
        bool flag = true; // flag = True means t increases, False means t decreases.
        while(i < n){
            if(flag)++t;
            else --t;
            v[i] = make_pair(t, i);
            i++;
            if(t == 1)flag = true;
            if(t == numRows)flag = false;
        }
        sort(v.begin(), v.end());
        for(auto it = v.begin(); it != v.end(); ++it)res += s[it->second];
        return res;
    }
};
