class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        int trappedRain = 0;
        int left = 0, right = n - 1;
        int max_left = height[left], max_right = height[right];
        
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    trappedRain += max_left - height[left];
                }
                left++;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    trappedRain += max_right - height[right];
                }
                right--;
            }
        }
        
        return trappedRain;
    }
};