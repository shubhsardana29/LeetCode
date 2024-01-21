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
    int recursionSol(TreeNode* root){
        // base case
        if(root==NULL) return 0;

        int leftSubtree = maxDepth(root->left);
        int rightSubtree = maxDepth(root->right);
        int ans = 1 + max(leftSubtree,rightSubtree);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        return recursionSol(root);
    }
};