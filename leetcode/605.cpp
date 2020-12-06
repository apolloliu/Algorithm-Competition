//O(M) M is the size of vector f 
class Solution {
public:
    bool solve(vector<int>&f, int n){
        int sum = 0;
        int m = f.size();
        for(int i = 0; i < m; ++i){
            if(!f[i] && (i == 0 || !f[i-1]) && (i == m-1 || !f[i+1]))f[i] = 1, sum++;
        }
        return sum >= n;
    }
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(solve(f, n))return true;
        return false;
    }
};

