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
    void level(TreeNode* root){
        queue<TreeNode* >qu;
        qu.push(root);
        qu.push(NULL);

        while(!qu.empty()){
            TreeNode* temp = qu.front();
            qu.pop();

            if(temp==NULL){
                // cout<<endl;
                if(!qu.empty()) qu.push(NULL);
            }
            else{
                //cout<<temp->data;
                if(temp->left!=NULL) qu.push(temp->left);
                if(temp->right!=NULL) qu.push(temp->right);
            }
        }
    }
    bool solve(TreeNode* p, TreeNode* q,int level){
        // base case
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;

        bool isRootEquals=false;

    
        if(p->val==q->val) isRootEquals=true;
        
        bool leftEquals=solve(p->left,q->left,level+1);
        bool rightEquals=solve(p->right,q->right,level+1);
        return (isRootEquals && leftEquals && rightEquals);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q,0);
    }
};