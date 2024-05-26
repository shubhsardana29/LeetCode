class Solution {
public:
    const int MOD = 1e9 + 7;
    int checkRecord(int n) {
        //  3D array for memoization with dimensions [n+1][2][3]
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dp(n, 0, 0, memo);
    }
private:
    int dp(int days_left, int A_count, int L_streak, vector<vector<vector<int>>>& memo) {
        if (days_left == 0) {
            return 1;
        }
        
        if (memo[days_left][A_count][L_streak] != -1) {
            return memo[days_left][A_count][L_streak];
        }
        
        int result = dp(days_left - 1, A_count, 0, memo);  // Add 'P'
        if (A_count == 0) {
            result = (result + dp(days_left - 1, 1, 0, memo)) % MOD;  // Add 'A'
        }
        if (L_streak < 2) {
            result = (result + dp(days_left - 1, A_count, L_streak + 1, memo)) % MOD;  // Add 'L'
        }
        
        memo[days_left][A_count][L_streak] = result;
        return result;
    }
};

