class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long countSub = 0;
        int lastMin = -1, lastMax = -1;
        int n = nums.size();

        for (int left=0,right = 0; right < n; right++) {
            // If the current number is outside the [minK, maxK] range, reset the left pointer
            if (nums[right] < minK || nums[right] > maxK) {
                left = right + 1;
            }
            
            // Update the last seen positions for minK and maxK
            if (nums[right] == minK) {
                lastMin = right;
            }
            if (nums[right] == maxK) {
                lastMax = right;
            }

            // If both minK and maxK are seen in the current window, update the count
            if (lastMin >= left && lastMax >= left) {
                countSub += min(lastMin, lastMax) - left + 1;
            }
        }

        return countSub;
    }
};