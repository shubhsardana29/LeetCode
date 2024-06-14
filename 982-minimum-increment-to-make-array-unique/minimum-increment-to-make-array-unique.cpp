class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= prev) {
                count += (prev + 1 - nums[i]);
                nums[i] = prev + 1;
            }
            prev = nums[i];
        }
        
        return count;
    }
};