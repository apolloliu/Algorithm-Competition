unordered_map<int, int>mp;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        mp.clear();
        int res = 0;
        mp[0] = 0;
        for(int i = 0; i < n; ++i){
            sum += (nums[i] ? 1 : -1);
            if(!mp.count(sum))mp[sum] = i+1;
            else res = max(res, i+1-mp[sum]);
            // cout << sum << endl;
        }
        return res;
    }
};
