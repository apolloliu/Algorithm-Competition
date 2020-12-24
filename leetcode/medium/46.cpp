// 回溯深搜，复杂度O(2^n)
class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>& tmp, vector<int>& nums, vector<bool>& vis){
        int n = nums.size();
        if(tmp.size() == n){res.push_back(tmp); return;}
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                vis[i] = 1;
                tmp.push_back(nums[i]);
                dfs(tmp, nums, vis);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        int n = nums.size();
        if(!n)return res;
        vector<int>tmp;
        vector<bool>vis(n);
        dfs(tmp, nums, vis);
        return res;
    }
};
