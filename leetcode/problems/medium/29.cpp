/***
将设 x/y = k
k 可以用二进制来表示，比如(10101),则
x = y*2^0 + y*2^2 + y*2^4
***/
class Solution {
public:
    bool is_pos(int x){
        return x >= 0;
    }
    int divide(int dividend, int divisor) {
        long long res = 0;
        bool flag = false;  // flase 代表同号
        long long dd = dividend, dr = divisor;
        if(is_pos(dd) && !is_pos(dr))dr = -dr, flag = true;
        if(is_pos(dr) && !is_pos(dd))dd = -dd, flag = true;
        if(!is_pos(dr) && !is_pos(dd))dd = -dd, dr = -dr;
        int t = 31;
        if(dd >= dr)
        while(t >= 0){
            long long tmp = pow(2, t)*dr;
            if(dd >= tmp){
                res += pow(2, t);
                dd -= tmp;
            }
            t--;
        }
        if(flag)res = -res;
        if(res >= INT_MAX)return INT_MAX;
        return (int)res;
    }
};
