class Solution {
public:
    int solveUsingRecursion(int n){
        if(n == 0 || n == 1) 
            return n; 
        
        return solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2); 
    }

    
    // int fib(int n) {
    //     //Step 1: create dp array
    //     vector<int>dp(n+1,-1);
    //     return solveUsingMem(n,dp);
    // }

    // int fib(int n) {
    //     return solveUsingTabulation(n);
    // }
    int fib(int n) {
        return solveUsingTabulationSpaceOptimised(n);
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
    int solveUsingTabulation(int n){
        //Step 1: CREATE DP ARRAY

        vector<int>dp(n+1,-1);

        // Step 2: analyze base case and fill dp aray
        dp[0]=0;
        if(n==0) return dp[0];
        dp[1]=1;

        // step 3: Fill the remaining dp array

        // already filled index 0 & 1 in size of n+1 i.e loop was 0 to n
        // so remaining size of loop = 2 -> n

        for(int i=2;i<n+1;i++){
            //copy paste the recursive logic
            //replace recursive calls with dp array
            // make sure dp array is using looping variable " i ";
            dp[i]=dp[i - 1] + dp[i - 2];
        }
        //ans return karna hai
        return dp[n];
    }
    int solveUsingTabulationSpaceOptimised(int n){

        // Step 2: analyze base case and fill dp aray
        int prev=0;
        if(n==0) return 0;
        int curr=1;

        int ans;
        for(int i=2;i<n+1;i++){
            //prev & current ko ek step aage move karna
            ans = curr + prev;
            prev= curr;
            curr= ans;

        }
        //ans return karna hai
        return ans;
    }
    /* dp
    1) top down - recursion + memoization
    2) bottom up - iterative/ tabulation method 
    3) bottom up - with space optimisation (only valid if pattern exits in ques)
    */
};