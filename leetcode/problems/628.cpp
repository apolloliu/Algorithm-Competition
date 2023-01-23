// O(nlogn)
const int inf = 0x7f7f7f7f;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = -inf;
        res = max(res, nums[0]*nums[1]*nums[2]);
        res = max(res, nums[0]*nums[1]*nums[n-1]);
        res = max(res, nums[0]*nums[n-1]*nums[n-2]);
        res = max(res, nums[n-1]*nums[n-2]*nums[n-3]);
        return res;
    }
};


// O(n), find the maximum 3 value and minimum 2 value
const int inf = 0x7f7f7f7f;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1, min2, max1, max2, max3;
        min1 = min2 = inf;
        max1 = max2 = max3 = -inf;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3){
                max3 = nums[i];
            }
        }
        int res = max(min1*min2*max1, max1*max2*max3);
        return res;
    }
};

