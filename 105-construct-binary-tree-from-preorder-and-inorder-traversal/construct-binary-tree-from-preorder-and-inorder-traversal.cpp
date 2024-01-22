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
    TreeNode* solve(vector<int>& preorder, int& preorderIndex, vector<int>& inorder, int inorderStart, int inorderEnd, int size) {
        // base case
        if (preorderIndex >= size || inorderStart > inorderEnd) return nullptr;

        // create the root node
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // find the index of the root in inorder
        int rootIndex;
        for (int i = inorderStart; i <= inorderEnd; ++i) {
            if (inorder[i] == rootValue) {
                rootIndex = i;
                break;
            }
        }

        // recursively build left and right subtrees
        root->left = solve(preorder, preorderIndex, inorder, inorderStart, rootIndex - 1, size);
        root->right = solve(preorder, preorderIndex, inorder, rootIndex + 1, inorderEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = preorder.size();
        return solve(preorder, preorderIndex, inorder, inorderStart, inorderEnd, size);
    }
};
