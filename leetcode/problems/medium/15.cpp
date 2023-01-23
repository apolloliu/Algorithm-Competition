// O(n^2) 双指针，简化为两数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tmp;
        vector<vector<int>>res;
        for(int i = 0; i < n; ++i){
            tmp = -nums[i];
            if(i && nums[i] == nums[i-1])continue; // 减去重复的情况，点睛之笔
            for(int j = i + 1, k = n - 1; j < k; ){
                if(nums[j] + nums[k] == tmp){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j + 1 <= k && nums[j] == nums[j+1])j++;
                    while(k - 1 >= j && nums[k] == nums[k-1])k--;
                    k--;
                    j++;
                }
                else if(nums[j] + nums[k] > tmp)k--;
                else j++;
                
            }
        }
        return res;
    }
};
