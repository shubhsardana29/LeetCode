class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }

        // Step 1: Count the frequency of each nums
        map<int, int> freq;
        for (int nums : nums) {
            freq[nums]++;
        }

        // Step 2: Try to form the groups
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int nums = it->first;
            int count = it->second;

            // If there are numss of this value, try to form groups
            if (count > 0) {
                for (int i = 0; i < k; ++i) {
                    int currentnums = nums + i;
                    if (freq[currentnums] < count) {
                        return false;
                    }
                    freq[currentnums] -= count;
                }
            }
        }

        return true;
    }
};