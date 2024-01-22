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
    void createMapping(vector<int>& inorder,int size, map<int,int>&valToIndexMap){
        for(int i=0;i<size;i++){
            int element=inorder[i];
            int index=i;
            valToIndexMap[element]=index;
        }
    }

    TreeNode* solve(map<int,int>&valToIndexMap,vector<int>& postorder, int& postorderIndex, vector<int>& inorder, int inorderStart, int inorderEnd, int size) {
        // base case
        if (postorderIndex >= size || inorderStart > inorderEnd) return nullptr;

        // create the root node
        int rootValue = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootValue);

        // find the index of the root in inorder

        int position = valToIndexMap[rootValue];

        // recursively build left and right subtrees

        // remember - right call first in postorder
        root->right = solve(valToIndexMap,postorder, postorderIndex, inorder, position + 1, inorderEnd, size);
        root->left = solve(valToIndexMap,postorder, postorderIndex, inorder, inorderStart, position - 1, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex =postorder.size()-1 ;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = postorder.size();
        map<int,int>valToIndexMap;
        createMapping(inorder,size,valToIndexMap);
        
        return solve(valToIndexMap,postorder, postorderIndex, inorder, inorderStart, inorderEnd, size);
    
    }
};