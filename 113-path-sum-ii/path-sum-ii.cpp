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
    void solve(TreeNode* root, int targetSum,vector<vector<int>>&finalAns,vector<int> temp,int sum){
        //base case
        if(root==NULL) return;
        //1 case khud se:
        sum+=root->val;
        temp.push_back(root->val);
        //leaf node
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                finalAns.push_back(temp);
            }
            else{
                return;
            }
        }

        //baaki recursion
        solve(root->left,targetSum,finalAns,temp,sum);
        solve(root->right,targetSum,finalAns,temp,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<vector<int>>finalAns;
        vector<int> temp;
        solve(root,targetSum,finalAns,temp,sum);
        return finalAns;
    }
};