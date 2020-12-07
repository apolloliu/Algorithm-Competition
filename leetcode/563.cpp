/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    void dfs(TreeNode* root){
        if(root == NULL)return;
        dfs(root->left);
        dfs(root->right);
        int l, r;
        l = r = 0;
        if(root->left != NULL)l = root->left->val;
        if(root->right != NULL)r = root->right->val;
        res += abs(l-r);
        root->val += l + r;
    }
    int findTilt(TreeNode* root) {
        if(root == NULL)return 0;
        res = 0;
        dfs(root);
        return res;
    }
};
