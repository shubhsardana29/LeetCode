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
    // int recursionSol(TreeNode* root){
    //     // base case
    //     if(root==NULL) return 0;

    //     int leftSubtree = maxDepth(root->left);
    //     int rightSubtree = maxDepth(root->right);
    //     int ans = 1 + max(leftSubtree,rightSubtree);
    //     return ans;
    // }
    int levelOrderSol(TreeNode* root){
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int count = 0;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front==NULL){
                // cout<<endl;
                if(!q.empty()){
                    count++;
                    q.push(NULL);
                }
            }
            else{
                // valid node wala case
                // cout<<front->val;
                if(front->left!=NULL) q.push(front->left);            
                if(front->right!=NULL) q.push(front->right);    
            }        
        }
        return count;
    }
    int maxDepth(TreeNode* root) {
        // return recursionSol(root);
        return (root==NULL) ? 0 :levelOrderSol(root)+1;
    }
};