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
    void dfs(TreeNode* t, string&s){
        if(t == NULL)return;
        s += to_string(t->val);

        if(t->left != NULL){
            s += '(';
            dfs(t->left, s);
            s += ')';
        }
        else if(t->right != NULL){
            s += "()";
        }
        if(t->right != NULL){
            s += '(';
            dfs(t->right, s);
            s += ')';
        }
    }
    string tree2str(TreeNode* t) {
        string s = "";
        dfs(t, s);
        return s;
    }
};

