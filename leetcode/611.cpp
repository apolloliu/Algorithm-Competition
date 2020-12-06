//O(N^2log(N))
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x, y, high;
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                x = nums[i], y = nums[j];
                high = x + y;
                int r = lower_bound(nums.begin(), nums.end(), high) - nums.begin();
                int cnt = r - j - 1;
                if(cnt >= 0)
                res += cnt;
            }
        }
        return res;
    }
};

// O(N^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x, y;
        int res = 0;
        for(int i = 0; i < n-2; ++i){
            k = i + 2;
            for(int j = i+1; j < n-1; ++j){
                while(k < n && nums[i] + nums[j] > nums[k]){
                    k++;
                }
                if(k - j - 1 >= 0)res += k - j - 1;
            }
        }
        return res;
    }
};
