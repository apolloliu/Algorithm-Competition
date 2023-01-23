//1111. Maximum Nesting Depth of Two Valid Parentheses Strings
// DP
//
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int sz = seq.size();
        int a = 0, b = 0;
        vector<int>v;
        for(int i = 0; i < sz; ++i){
            if(seq[i] == '('){
                if(a <= b)a++, v.push_back(0);
                else b++, v.push_back(1);
            }
            else {
                if(a >= b)a--, v.push_back(0);
                else b--,  v.push_back(1);
            }
        }
        return v;
    }
};
