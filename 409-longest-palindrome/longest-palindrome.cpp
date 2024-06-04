class Solution {
public:
    int longestPalindrome(std::string s) {
        int count = 0;
        int freq[128] = {0}; 
        
        for (char ch : s) {
            freq[ch]++;
        }
        
        for (int i = 0; i < 128; ++i) {
            count += (freq[i] / 2) * 2;  // Add the even part of the frequency
            if (count % 2 == 0 && freq[i] % 2 == 1) {
                count++;  // If count is even and we encounter an odd frequency, add one to allow for a central character
            }
        }
        
        return count;
    }
};
