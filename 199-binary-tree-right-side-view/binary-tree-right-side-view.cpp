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
        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp==NULL){
                // cout<<endl;
                if(!q.empty()) q.push(NULL);
            }
            else{
                //cout<<temp->data;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
    }
    void solve(TreeNode*root , int level,vector<int>&temp){
        //base case
        if(root==nullptr) return;
        // 1 case khud se
        int size=temp.size();
        if(size==level) temp.push_back(root->val);
        //baaki recursion
        // to get rightview first , right call first
        solve(root->right,level+1,temp);
        solve(root->left,level+1,temp);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> temp;
        solve(root,0,temp);
        return temp;
    }
};