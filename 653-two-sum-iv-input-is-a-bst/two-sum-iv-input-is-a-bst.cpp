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
    void storeinorder(TreeNode* root, vector<int>&inorder){
        if(root==NULL) return;
        //inordr= lnr
        //L
        storeinorder(root->left,inorder);
        //N
        inorder.push_back(root->val);
        //R
        storeinorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        storeinorder(root,inorder);

        // find target using two pointer approach
        int n = inorder.size();
        int start=0;
        int end=n-1;
        while(start<end){
            if(inorder[start]+inorder[end]==k) return true;
            else if(inorder[start]+inorder[end]<k){
                // findtarget(root->right,k);
                start++;
            }
            else{
                // findtarget(root->left,k);
                end--;
            }
        }
        return false;
    }
};