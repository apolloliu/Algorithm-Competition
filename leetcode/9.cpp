class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        long long res = 0;
        int n = x;
        while(n){
            res *= 10;
            res += n%10;
            n /= 10;
        }
        if(res == x)return true;
        else return false;
    }
};
