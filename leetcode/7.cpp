class Solution {
public:
    int reverse(int n) {
        long long res = 0;
        while(n){
            res *= 10;
            res += n%10;
            n /= 10;
        }
        if(res > INT_MAX || res < INT_MIN)res = 0;
        return res;
    }
};
