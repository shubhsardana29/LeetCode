// recursion solution - (TLE)

// class Solution {
// public:
//     int robHelper(vector<int>& nums,int i){
//         // base case
//         if(i>=nums.size()) return 0;

//         // sol for 1 case
//         int robAmt1 = nums[i] + robHelper(nums,i+2);
//         int robAmt2 = 0 + robHelper(nums,i+1);

//         return max(robAmt1,robAmt2);
//     }
//     int rob(vector<int>& nums) {
//         return robHelper(nums,0);
        
//     }
// };

// dp solution

class Solution {
public:
    // time/space: O(n)/O(1)
    int rob(vector<int>& nums) {
        int dp0 = 0, dp1 = 0;
        for (auto& num : nums) {
            int curr = max(dp0 + num /* take */, dp1 /* skip (not take) */);
            dp0 = dp1;
            dp1 = curr;
        }
        return max(dp0, dp1);
    }
};