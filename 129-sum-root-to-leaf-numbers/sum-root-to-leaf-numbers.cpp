class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
    
    int sumNumbersHelper(TreeNode* root, int currentSum) {
        if (root == nullptr) {
            return 0;
        }
        
        currentSum = currentSum * 10 + root->val;
        
        //  leaf node - return the current sum
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum;
        }
        
        int leftSum = sumNumbersHelper(root->left, currentSum);
        int rightSum = sumNumbersHelper(root->right, currentSum);
        
        return leftSum + rightSum;
    }
};
