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
    int res = 0;
    void inOrder(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            res = max(res, abs(high-low));
            return;
        }
        inOrder(root->left, min(low, root->val), max(high, root->val));
        inOrder(root->right, min(low, root->val), max(high, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int low = root->val, high = root->val;
        inOrder(root, low, high);
        return res;
    }
};