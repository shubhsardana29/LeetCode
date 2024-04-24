class Solution {
public:
    int tribonacci(int n) {
        // return solveUsingRecursion(n);
        vector<int>dp(n+1,-1);
        return solveUsingMemo(n,dp);
    }
    int solveUsingMemo(int n,vector<int>&dp){
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=solveUsingMemo(n-1,dp)+solveUsingMemo(n-2,dp)+solveUsingMemo(n-3,dp);
        return dp[n];
    }
};