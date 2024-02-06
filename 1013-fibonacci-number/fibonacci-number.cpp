class Solution {
public:
    int solveUsingRecursion(int n){
        if(n == 0 || n == 1) 
            return n; 
        
        return solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2); 
    }
    
    int fib(int n) {
        //Step 1: create dp array
        vector<int>dp(n+1,-1);
        return solveUsingMem(n,dp);
    }

    int solveUsingMem(int n,vector<int>& dp){
        if(n == 0 || n == 1) return n; 
        //Step 3: if ans already present or not
        if(dp[n]!=-1){
            return dp[n];
        }

        // Step 2: store and return using dp aray
        dp[n]= solveUsingMem(n - 1,dp) + solveUsingMem(n - 2,dp);
        return dp[n]; 
    }
    /* dp
    1) top down - recursion + memoization
    2) bottom up - iterative/ tabulation method 
    */
};