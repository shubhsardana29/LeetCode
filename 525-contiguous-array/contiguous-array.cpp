class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxTillNow = 0;
        unordered_map<int, int> balanceMap; // to store balance and index
        int balance = 0;

        // initially balance = 0 at index= -1
        balanceMap[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            balance += (nums[i] == 0) ? 1 : -1; 

            if (balanceMap.find(balance) != balanceMap.end()) {
                // Update maxTillNow if the current subarray length is greater
                maxTillNow = max(maxTillNow, i - balanceMap[balance]);
            } else {
                // Store the first occurrence of the balance
                balanceMap[balance] = i;
            }
        }

        return maxTillNow;
    }
};