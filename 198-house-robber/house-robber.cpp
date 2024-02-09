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

// class Solution {
// public:
//     int solveUsingTopDownDp(vector<int>& nums,int index,vector<int>&dp){
//         // base case
//         if(index>=nums.size()) return 0;

//         //check if answer already exists
//         if(dp[index]!=-1) return dp[index];

        
//         int robAmt1 = nums[index] + solveUsingTopDownDp(nums,index+2,dp);
//         int robAmt2 = 0 + solveUsingTopDownDp(nums,index+1,dp);

//         return dp[index]=max(robAmt1,robAmt2);
//     }
//     int rob(vector<int>& nums) {
//         int index=0;
//         int n=nums.size();
//         vector<int>dp(n,-1);
//         return solveUsingTopDownDp(nums,index,dp);
        
//     }
// };

//Bottom up DP solution - Tabulation method

// class Solution {
// public:
//     int solveUsingBottomUpDp(vector<int>& nums){
//         //create dp aaray
//         int n=nums.size();
//         vector<int>dp(n,-1);
//         // analyze base case and fill initial dp array
//          dp[n-1]=nums[n-1];

//         //fill remaining dp array : analyzie loop initalization conditions
//         for(int index=n-2;index>=0;index--){
//             int tempAns=0;
//             if(index+2<n){
//                 tempAns=dp[index+2];   //to resolve out of bound error
//             }
//             int robAmt1 = nums[index] + tempAns;
//             int robAmt2 = 0 + dp[index+1];
//             dp[index]=max(robAmt1,robAmt2);
//         }

//         return dp[0];
//     }
// }; 


// space optimised technique
class Solution {
public:
    int solveUsingBottomUpDpSpaceOpti(vector<int>& nums){
        
        int n=nums.size();
        int prev=nums[n-1];
        int curr=0;
        int next=0;

        for(int index=n-2;index>=0;index--){
            int tempAns=0;
            if(index+2<n){
                tempAns=next;   //to resolve out of bound error
            }
            int robAmt1 = nums[index] + tempAns;
            int robAmt2 = 0 + prev;
            curr=max(robAmt1,robAmt2);

            //imp step
            next=prev;
            prev=curr;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        return solveUsingBottomUpDpSpaceOpti(nums); 
    }
};

