/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* add = new TreeNode(val);
            add->left = root;
            return add;
        }
        solve(root, val, depth, 1);
        return root;
    }
    void solve(TreeNode* root, int val, int depth, int level) {
        if (!root)
            return;
        if (level == depth - 1) {
            TreeNode* add = root->left;
            root->left=new TreeNode(val);
            root->left->left=add;

            add=root->right;
            root->right=new TreeNode(val);
            root->right->right=add;
        }
        else{
            solve(root->left, val, depth, level+1);
            solve(root->right, val, depth, level+1);
        }
    }
};