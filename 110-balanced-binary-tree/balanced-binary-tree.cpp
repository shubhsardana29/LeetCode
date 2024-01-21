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
    int height(TreeNode* root){
        //base case
        if(root==NULL) return 0;
        //---
        int leftSubtree = height(root->left);
        int rightSubtree = height(root->right);
        int ans = 1 + max(leftSubtree, rightSubtree);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        //base case: 
        if(root==NULL) return 1;
        //--------------------------
        int leftSubtreeHeight = height(root->left);
        int rightSubtreeHeight = height(root->right);


        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        int diff = abs(leftSubtreeHeight-rightSubtreeHeight);

        //1 case khud se:
        if(diff<=1 && leftBalanced && rightBalanced) {
            return 1;
        }
        else{
            return 0;
        }
        
    }
};