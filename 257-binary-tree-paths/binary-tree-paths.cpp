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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> finalAns;
        // base case
        if (root == nullptr) return finalAns;

        // leaf node
        if (root->left == nullptr && root->right == nullptr) {
            finalAns.push_back(to_string(root->val));
            return finalAns;
        }

        vector<string> leftAns = binaryTreePaths(root->left);
        vector<string> rightAns = binaryTreePaths(root->right);

        // concatenate the current node's value to each path in the left subtree
        for (const string& path : leftAns) {
            finalAns.push_back(to_string(root->val) + "->" + path);
        }

        // concatenate the current node's value to each path in the right subtree
        for (const string& path : rightAns) {
            finalAns.push_back(to_string(root->val) + "->" + path);
        }

        return finalAns;
    }
};
