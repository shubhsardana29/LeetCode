class Solution {
private:
    int numberOfArithmeticSlices(std::vector<int>& nums, int nextIndex, long long commonDiff, int size) {
        int total = 0;
        if (size >= 3) total += 1;
        for (int i = nextIndex; i < nums.size(); i++) {
            long long previous = nums[nextIndex - 1];
            if ((nums[i] - previous) == commonDiff) {
                total += numberOfArithmeticSlices(nums, i + 1, commonDiff, size + 1);
            }
        }
        return total;
    }
    
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        bool isAllElementsEqual = std::all_of(nums.begin(), nums.end(), [&](int num) { return num == nums[0]; });
        if (isAllElementsEqual) {
            int totalSubsequence = std::pow(2, nums.size()) - 1;
            int oneSizedSubsequence = nums.size();
            int twoSizedSubsequence = (nums.size() * (nums.size() - 1)) / 2;
            return totalSubsequence - oneSizedSubsequence - twoSizedSubsequence;
        }

        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long commonDiff = (long long)nums[j] - (long long)nums[i]; // Avoids overflow
                ans += numberOfArithmeticSlices(nums, j + 1, commonDiff, 2);
            }
        }
        return ans;
    }
};