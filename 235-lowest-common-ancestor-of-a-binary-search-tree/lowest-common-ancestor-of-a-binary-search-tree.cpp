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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return NULL;

        if(p->val<root->val && q->val<root->val){
            TreeNode* leftSubtree = lowestCommonAncestor(root->left,p, q);
            return leftSubtree;
        }
        if(p->val>root->val && q->val>root->val){
            TreeNode* rightSubtree = lowestCommonAncestor(root->right,p, q);
            return rightSubtree;
        }
        return root;
    }
};