// leetcode 525 Contiguous Array
// 题意是说，给一个数组（只含0和1），求包含相同个数0和1的最长子数组的长度
// 方法: 有0则减一，有1则加1，记录子串和相等数组长度，找最大值
//
// 拓展: 和[1]很相似，但是后者多了个条件
// [1]: http://codeforces.com/contest/1138/problem/A

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
