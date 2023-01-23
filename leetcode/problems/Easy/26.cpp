// 双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())return 0;
        int i, j, val = nums[0];
        for(i = 1, j = 1; j < nums.size(); ++j){
            if(nums[j] != val){
                nums[i++] = nums[j];
                val = nums[j];
            }
        }
        return i;
    }
};
