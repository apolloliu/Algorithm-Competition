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
    TreeNode* dfs(TreeNode* root, int v, int d, int dep){
        if(d == 1){
            TreeNode* tmp = new TreeNode(v);
            tmp->left = root;
            return tmp;
        }
        if(d == dep + 1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* tmp1 = new TreeNode(v);
            TreeNode* tmp2 = new TreeNode(v);
            root->left = tmp1;
            root->right = tmp2;
            tmp1->left = left;
            tmp2->right = right;   
            return root;
        }
        if(root->left != NULL)
        root->left = dfs(root->left, v, d, dep+1);
        if(root->right != NULL)
        root->right = dfs(root->right, v, d, dep+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode* res = dfs(root, v, d, 1);
        return res;
    }
};

