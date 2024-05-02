class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxK = -1;
        for (int num : nums) {
            if (binary_search(nums.begin(), nums.end(), -num)) {
                maxK = max(maxK, num);
            }
        }
        
        return maxK;

    }
};