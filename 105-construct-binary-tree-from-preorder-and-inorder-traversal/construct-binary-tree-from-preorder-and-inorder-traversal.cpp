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

    TreeNode* solve(map<int,int>&valToIndexMap,vector<int>& preorder, int& preorderIndex, vector<int>& inorder, int inorderStart, int inorderEnd, int size) {
        // base case
        if (preorderIndex >= size || inorderStart > inorderEnd) return nullptr;

        // create the root node
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // find the index of the root in inorder

        int position = valToIndexMap[rootValue];

        // recursively build left and right subtrees
        root->left = solve(valToIndexMap,preorder, preorderIndex, inorder, inorderStart, position - 1, size);
        root->right = solve(valToIndexMap,preorder, preorderIndex, inorder, position + 1, inorderEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = preorder.size();
        map<int,int>valToIndexMap;
        createMapping(inorder,size,valToIndexMap);
        
        return solve(valToIndexMap,preorder, preorderIndex, inorder, inorderStart, inorderEnd, size);
    }
};
