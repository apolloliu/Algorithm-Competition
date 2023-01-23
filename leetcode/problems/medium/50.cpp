// 快速幂，时间复杂度O(logN)
class Solution {
public:
    double myPow(double x, int m) {
        double res = 1.;
        for(long long n =abs((long long)m); n; n >>=1 ){
            if(n&1)res *= x;
            x *= x;
        }
        if(m < 0)res = 1. / res;
        return res;
    }
};
