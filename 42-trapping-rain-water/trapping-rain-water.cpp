class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // No bars, no trapped water

        vector<int> maxLeft(n, 0), maxRight(n, 0);

        // Calculate maxLeft for each position
        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }

        // Calculate maxRight for each position
        maxRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        // Calculate trapped water
        int trappedWater = 0;
        for (int i = 0; i < n; ++i) {
            trappedWater += max(0, min(maxLeft[i], maxRight[i]) - height[i]);
        }

        return trappedWater;
    }
};