// 二分查找，查找上限和下限
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        // find the minimum index
        int x1 = -1, x2 = -1;
        if(!n)return {x1, x2};
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] >= target)r = m - 1;
            else l = m + 1;
        }
        if(l < n && target == nums[l])x1 = l;
        
        // find the maximum index
        l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] <= target)l = m + 1;
            else r = m - 1;
        }
        if(r >= 0 && target == nums[r])x2 = r;
        vector<int> res = {x1, x2};
        return res;
    }
};
