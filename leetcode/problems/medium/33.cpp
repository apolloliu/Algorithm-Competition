// 升序数组经过某点旋转，仍然可以用二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] == target)return m;
            else if(nums[l] < nums[m] && target >= nums[l] && target < nums[m]){
                r = m - 1;
            }
            else if(nums[l] > nums[m] && (target >= nums[l] || target < nums[m])){
                r = m - 1;
            }
            else if(nums[m] < nums[r] && target > nums[m] && target <= nums[r]){
                l = m + 1;
            }
            else l = m + 1;
        }
        if(nums[l] == target)return l;
        else return -1;
    }
};
