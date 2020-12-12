// O(n^2) 双指针
const int inf = 0x7f7f7f7f;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, mm = inf;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            for(int j = i + 1, k = n - 1; j < k; ){
                if(abs(nums[i] + nums[j] + nums[k] - target) < mm){
                    res = nums[i] + nums[j] + nums[k];
                    mm = abs(nums[i] + nums[j] + nums[k] - target);
                }
                if(nums[i] + nums[j] + nums[k] >= target)k--;
                else j++;
            }
        }
        return res;
    }
};
