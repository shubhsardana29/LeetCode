class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> c({{0, 1}});
        int prefixsum = 0;
        int ans = 0;
        for (int i : nums) {
            prefixsum += i;
            ans += c[prefixsum - goal];
            c[prefixsum]++;
        }
        return ans;
    }
};