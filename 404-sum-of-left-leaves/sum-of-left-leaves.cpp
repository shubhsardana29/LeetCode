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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        
        int sum = 0;
        sumOfLeftLeavesHelper(root, false, sum);
        return sum;
    }
    void sumOfLeftLeavesHelper(TreeNode* node, bool isLeft, int& sum) {
        if (!node) return;

        if (isLeft && !node->left && !node->right) {
            sum += node->val;
            return;
        }

        sumOfLeftLeavesHelper(node->left, true, sum);
        sumOfLeftLeavesHelper(node->right, false, sum);
    }
};