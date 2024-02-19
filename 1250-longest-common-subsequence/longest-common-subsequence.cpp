class Solution {
public:
    // int solveUsingRecursion(string a,string b,int i,int j){
    //     //base case
    //     if(i>=a.length()){
    //         return 0;
    //     }
    //     if(j>=b.length()){
    //         return 0;
    //     }
    //     int ans;
    //     // recursive call
    //     if(a[i]==b[j]){
    //         ans=1+solveUsingRecursion(a,b,i+1,j+1);
    //     }
    //     else{
    //         int caseA=solveUsingRecursion(a,b,i,j+1);
    //         int caseB=solveUsingRecursion(a,b,i+1,j);
    //         ans=0+max(caseA,caseB);
    //     }
    //     return ans;
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int i=0;
    //     int j=0;
    //     return solveUsingRecursion(text1,text2,i,j);
    // }

    // int solveUsingMem(string& a,string& b,int i,int
    // j,vector<vector<int>>&dp){
    //     //base case
    //     if(i>=a.length() || j>=b.length()){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans;
    //     // recursive call
    //     if(a[i]==b[j]){
    //         ans=1+solveUsingMem(a,b,i+1,j+1,dp);
    //     }
    //     else{
    //         int caseA=solveUsingMem(a,b,i,j+1,dp);
    //         int caseB=solveUsingMem(a,b,i+1,j,dp);
    //         ans=0+max(caseA,caseB);
    //     }
    //     dp[i][j]=ans;
    //     return dp[i][j];
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int i=0;
    //     int j=0;
    //     vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length(),-1));
    //     return solveUsingMem(text1,text2,i,j,dp);
    // }

    int solveUsingTab(string a, string b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i_index = a.length() - 1; i_index >= 0; i_index--) {
            for (int j_index = b.length() - 1; j_index >= 0; j_index--) {
                int ans;
                // recursive call
                if (a[i_index] == b[j_index]) {
                    ans = 1 + dp[i_index + 1][j_index + 1];
                } else {
                    int caseA = dp[i_index][j_index + 1];
                    int caseB = dp[i_index + 1][j_index];
                    ans = max(caseA, caseB);
                }
                dp[i_index][j_index] = ans;
            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solveUsingTab(text1, text2);
    }
};