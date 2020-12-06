/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL)return NULL;
        TreeNode *res = NULL;
        if(t1 == NULL && t2 != NULL){
            res = new TreeNode(t2->val);
            res->left = dfs(t1, t2->left);
            res->right = dfs(t1, t2->right);
        }
        else if(t1 != NULL && t2 == NULL){
            res = new TreeNode(t1->val);
            res->left = dfs(t1->left, t2);
            res->right = dfs(t1->right, t2);
        }
        else {
            res = new TreeNode(t1->val+t2->val);
            res->left = dfs(t1->left, t2->left);
            res->right = dfs(t1->right, t2->right);
        }
        return res;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *res = dfs(t1, t2);
        return res;
    }
};

