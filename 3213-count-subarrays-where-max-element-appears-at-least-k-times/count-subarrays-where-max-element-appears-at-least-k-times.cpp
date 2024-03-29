class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums), end(nums));
        int n = nums.size();
        long long result = 0;
        int countMax = 0;

        for (int i = 0, j = 0; j < n; ++j) {
            if (nums[j] == maxE) {
                countMax++;
            }

            while (countMax >= k) {
                result += n - j;
                if (nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
        }

        return result;
    }
};
