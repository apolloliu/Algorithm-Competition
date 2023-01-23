class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp.clear();
        vector<int>res;
        res.clear();
        for(int i = 0; i < n; ++i){
            if(mp.find(target-nums[i]) != mp.end()){
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};

