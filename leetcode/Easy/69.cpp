// O(logn)  二分
class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while(l <= r){
            int m = l + (r - l) / 2;
            if((long long)m*m == x)return m;
            else if(1LL*m*m > 1LL*x)r = m - 1;
            else l = m + 1;
        }
        return r;
    }
};
