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
    TreeNode* maxValue(TreeNode* root){
        if(root==NULL) return root;
        TreeNode* temp=root;
        while(temp->right){
            temp=temp->right;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //target ko dhundo 
        // target ko delete kardo

        if(!root) return NULL;
        if(root->val==key){
            //ab delete karenge
            //4 cases  
         //case 1: if leaf node
         if(root->left==NULL && root->right==NULL){
             delete root;
             return NULL;
         }
         else if(root->left!=NULL && root->right==NULL){
             TreeNode* leftSubtree= root->left;
             delete root;
             return leftSubtree;
         }
         else if(root->left==NULL && root->right!=NULL){
             TreeNode* rightSubtree= root->right;
             delete root;
             return rightSubtree;
         }
         else{
             TreeNode* maxi=maxValue(root->left);
             root->val=maxi->val;

             //important to delete maxi data node in the left subtree
             root->left=deleteNode(root->left,maxi->val);
             return root;
         }
        }
        else if(root->val>key){
            //left mai chale jao
             root->left=deleteNode(root->left,key);
        }
        else{
            root->right= deleteNode(root->right,key);
        }
        return root;
    }
};
