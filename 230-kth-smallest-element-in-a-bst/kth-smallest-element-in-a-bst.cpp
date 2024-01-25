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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return -1;
    // indorder == LNR
        // L
        int leftSubtree = kthSmallest(root->left,k);
        if(leftSubtree!=-1) return leftSubtree;
        //N
        k--;
        if(k==0) return root->val;
        //R
        int rightSubtree = kthSmallest(root->right,k);
        // if(rightSubtree!=-1) 
        return rightSubtree;
    }
};