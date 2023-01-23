// O(n^3) 双指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        res.clear();
        if(!nums.size())return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i && nums[i] == nums[i-1])continue;
            for(int j = i + 1; j < n; ){
                // if(nums[j] == nums[j-1])continue;
                int sum = nums[i] + nums[j];
                for(int k = j + 1, l = n - 1; k < l; ){
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1])k++;
                        while(k < l && nums[l] == nums[l+1])l--;
                        
                    }
                    else if(sum + nums[k] + nums[l] > target)l--;
                    else k++;
                }
                j++;
                while(j < n && nums[j] == nums[j-1])j++;
            }
        }
        return res;
    }
};
