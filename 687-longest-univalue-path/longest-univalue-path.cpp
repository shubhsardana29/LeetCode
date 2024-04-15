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
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }

    int solve(TreeNode* root,int &maxi){
        if(root==nullptr) return 0;

        int left = solve(root->left,maxi);
        int right= solve(root->right,maxi);

        int leftPath = (root->left && root->left->val == root->val) ? left + 1 : 0;
        int rightPath = (root->right && root->right->val == root->val) ? right + 1 : 0;

        maxi = max(maxi, leftPath + rightPath);

        int ans = max(leftPath , rightPath);
        return ans;
    }
};