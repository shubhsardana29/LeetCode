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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        // 1 case khud se
        if (root->val == val) return root;

        TreeNode* searchResult = nullptr; 

        if (root->val > val) {
            searchResult = searchBST(root->left, val);
        } else {
            searchResult = searchBST(root->right, val);
        }

        return searchResult;
    }
};
