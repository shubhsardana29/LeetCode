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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // To indicate the end of a level
        int level = 0;
        int prev_val = (level % 2 == 0) ? numeric_limits<int>::min() : numeric_limits<int>::max();

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == nullptr) {
                if (!q.empty()) {
                    q.push(nullptr);
                    level++;
                    prev_val = (level % 2 == 0) ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }
            } else {
                // Check even-indexed level
                if (level % 2 == 0) {
                    if (front->val % 2 == 0 || front->val <= prev_val) {
                        return false;
                    }
                }
                // Check odd-indexed level
                else {
                    if (front->val % 2 != 0 || front->val >= prev_val) {
                        return false;
                    }
                }

                prev_val = front->val;

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return true;
    }
};