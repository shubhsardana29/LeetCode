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
/// method 2 using morris traversal: T.C=O(N) , S.C=O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        TreeNode* current=root;
        while(current){
            // if left is null, visit it
            if(current->left==NULL){
                result.push_back(current->val);
                current=current->right;
            } 
            // left node is not null
            else{
                // find inorder predecessor
                TreeNode* pred = current->left;
                while(pred->right!= current && pred->right){
                    pred=pred->right;
                }

                // if pred right node is null then go left after establishing link from predecessor to current
                if(pred->right==NULL){
                   pred->right=current;
                   current=current->left; 
                }
                else{
                    // left is already visited,go right after visiting curr while removing connection
                    pred->right=nullptr;
                    result.push_back(current->val);
                    current=current->right;
                }
            }
        }
        return result;
    }
};