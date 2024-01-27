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
    // void countNodes(TreeNode* root,int &count){
    //     if(!root) return;
    //     count++;
    //     countNodes(root->left,count);
    //     countNodes(root->right,count);
    // }
    bool levelOrderTraversal(TreeNode* root){
        queue<TreeNode* >q;
        q.push(root);
        // q.push(NULL);
        bool nullFound=false;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front==NULL){
                // cout<<endl;
                // if(!q.empty()) q.push(NULL);
                nullFound = true;
            }
            else{
                //cout<<temp->data;
                if(nullFound) return false;
                // if(front->left!=NULL) 
                q.push(front->left); 
                // if(front->right!=NULL) 
                q.push(front->right);  
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        // int totalNodes = 0;
        // countNodes(root,totalNodes);
        // int lastNode=0;
        return levelOrderTraversal(root);
        // if(lastNode>totalNodes) return false;
        
    }
};