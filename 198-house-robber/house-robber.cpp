//recursion solution - (TLE)

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


//Top down DP solution - recursion + memoization

class Solution {
public:
    int solveUsingTopDownDp(vector<int>& nums,int index,vector<int>&dp){
        // base case
        if(index>=nums.size()) return 0;

        //check if answer already exists
        if(dp[index]!=-1) return dp[index];

        // sol for 1 case
        int robAmt1 = nums[index] + solveUsingTopDownDp(nums,index+2,dp);
        int robAmt2 = 0 + solveUsingTopDownDp(nums,index+1,dp);

        return dp[index]=max(robAmt1,robAmt2);
    }
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solveUsingTopDownDp(nums,index,dp);
        
    }
};

