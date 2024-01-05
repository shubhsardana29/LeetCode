class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for (int num : nums) {
            if (tail.empty() || num > tail.back()) {
                tail.push_back(num);
            } else {
                *lower_bound(tail.begin(), tail.end(), num) = num;
            }
        }
        return tail.size();
    }
};