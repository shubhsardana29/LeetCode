// recursion - TLE

// class Solution {
// public:

//     int coinChange(vector<int>& coins, int amount) {
//        int ans=solveUsingRecursion(coins, amount);
//        if(ans==INT_MAX) return -1;
//        else{
//            return ans;
//        }
//     }
//     int solveUsingRecursion(vector<int>& coins, int amount){
//         //base case
//         if(amount==0) return 0;

//         //recursive relation
//         int mini=INT_MAX;

//         for(int i=0;i<coins.size();i++){
//             int tempAns=0;
//             //call recursion only for valid amounts i.e >=0 wale amount
//             if(amount-coins[i]>=0){
//                 tempAns=solveUsingRecursion(coins,amount-coins[i]);
//                 //find ans using i-th coin
//                 if(tempAns!=INT_MAX){
//                     int ans=1+tempAns;
//                     mini=min(mini,ans);
//                 }
//             }
//         }
//         return mini;
//     }
// };

// TOP - DOWN DP == RECURSION+ MEMOIZATION

// class Solution {
// public:

//     int coinChange(vector<int>& coins, int amount) {
//        int n=amount;
//        vector<int>dp(n+1,-1);
//        int ans=solveUsingMem(coins, amount,dp);
//        if(ans==INT_MAX) return -1;
//        else{
//            return ans;
//        }
//     }
//     int solveUsingMem(vector<int>& coins, int amount,vector<int>&dp){
//         //base case
//         if(amount==0) return 0;

//         //step 3: check if ans already exists
//         if(dp[amount]!=-1) return dp[amount];

//         //step2: store and return using dp array

//         //recursive relation
//         int mini=INT_MAX;

//         for(int i=0;i<coins.size();i++){
//             int tempAns=0;
//             //call recursion only for valid amounts i.e >=0 wale amount
//             if(amount-coins[i]>=0){
//                 tempAns=solveUsingMem(coins,amount-coins[i],dp);
//                 //find ans using i-th coin
//                 if(tempAns!=INT_MAX){
//                     int ans=1+tempAns;
//                     mini=min(mini,ans);
//                 }
//             }
//         }
//         dp[amount]=mini;
//         return dp[amount];
//     }
// };

// BOTTOM UP DP == TABULATION

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int ans = solveUsingTab(coins, amount);
        if (ans == INT_MAX)
            return -1;
        else {
            return ans;
        }
    }
    int solveUsingTab(vector<int>& coins, int amount) {
        // step 1: create dp array
        int n = amount;
        vector<int> dp(n + 1, -1);
        // step 2: analyze base case and fill initial dp array
        dp[0] = 0;

        // step 3: fill remaining dp array: analyze loop initialization
        // condition
        for (int value = 1; value <= amount; value++) {
            int mini = INT_MAX;

            for (int i = 0; i < coins.size(); i++) {
                int tempAns = 0;
                if (value - coins[i] >= 0) {
                    tempAns = dp[value - coins[i]];
                    if (tempAns != INT_MAX) {
                        int ans = 1 + tempAns;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[value] = mini;
        }

        return dp[amount];
    }
};