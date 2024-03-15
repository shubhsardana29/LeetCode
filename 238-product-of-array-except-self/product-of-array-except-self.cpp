class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int product = 1; 
        int zeroCount = 0; 
        
        // Compute the product of all elements and count zeros
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
                continue; // Skip multiplying zeros
            }
            product *= num;
        }
        
        // If there is more than one zero, all elements in the result will be 0
        if (zeroCount > 1) {
            ans = vector<int>(n, 0);
        } else if (zeroCount == 1) {
            // If there is only one zero, all elements except the zero will be 0
            for (int num : nums) {
                ans.push_back(num == 0 ? product : 0);
            }
        } else {
            // If there are no zeros, divide the product by nums[i] for each element
            for (int i = 0; i < n; ++i) {
                ans.push_back(product / nums[i]);
            }
        }
        
        return ans;
    }
};