class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        int n=s.size();
        bool odd=false;

        unordered_map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        // Calculate the length of the longest palindrome
        for (auto it : freq) {
            if (it.second % 2 == 0) { // even frequency of character
                count += it.second;
            } else { // odd frequency
                count += it.second - 1;
                odd = true;
            }
        }
        return odd==1 ? count+1 : count;
    }
};