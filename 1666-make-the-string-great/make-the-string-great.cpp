class Solution {
public:
    string makeGood(string s) {
        int j = -1; 
        for (int i = 0; i < s.size(); ++i) {
            if (j >= 0 && abs(s[i] - s[j]) == 32) {
                // If current and last valid characters form a bad pair, skip them
                --j;
            } else {
                // Update last valid character and move both pointers forward
                s[++j] = s[i];
            }
        }
        // Construct the resulting string using substring from 0 to j+1
        return s.substr(0, j + 1);
    }
};