// 只要从后往前找到最大的数，如果最大的数是第一位，将数组排序，直接返回即可；否则将最大数的前面一位替换成后面数据中最小而且比它大的数，然后之后的部分排序即可
// 测试样例
// [1,5,3,4,3,2]
// [1,5,4,2,3,3]

// [1,4,3,2]
// [2,1,3,4]
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        if(n >= 2){
            if(nums[n-1] > nums[n-2]){swap(nums[n-1], nums[n-2]); return;}
            int i;
            for(i = n - 1; i >= 1; --i){
                if(nums[i-1] < nums[i])break;
            }
            if(!i){sort(nums.begin(), nums.end()); return;}
            int mm = INT_MAX, x = nums[i-1], id;
            for(int j = i; j < n; ++j){
                if(mm > nums[j] && nums[j] > x){
                    mm = nums[j];
                    id = j;
                }
            }
            swap(nums[id], nums[i-1]);
            sort(nums.begin()+i, nums.end());
        }
    }
};

