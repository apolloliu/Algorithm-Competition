// leetcode 1. Two Sum
//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        mp.clear();
        int n = nums.size();
        int a[2];
        for(int i = 0; i < n; ++i){
            int x = nums[i];
            if(mp.count(target-x)){
                a[1] = i;
                a[0] = mp[target-x];
                break;
            }
            mp[x] = i;
        }
        vector<int>res(a, a+2);
        return res;
    }
};
