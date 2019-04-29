// Lintcode: find peak element
// https://www.lintcode.com/problem/find-peak-element/description
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int n = A.size();
        int l = 0, r = n-1;
        int T = 200;
        while(T--){
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            //cerr<<m1<<' '<<m2<<endl;
            if(A[m1] <= A[m2])l = m1;
            else r = m2;
        }
        return r-1;
    }
};
