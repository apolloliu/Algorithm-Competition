// leetcode 494. Target Sum
int res;
bool vis[22];
void dfs(vector<int>& nums, int cur, int sum, int S){
    if(cur == nums.size()){if(S == sum) res++; return ;}
    dfs(nums, cur+1, sum+nums[cur], S);
    dfs(nums, cur+1, sum-nums[cur], S);
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        res = 0;
        memset(vis, 0, sizeof(vis));
        dfs(nums, 0, 0, S);
        return res;
    }
};
