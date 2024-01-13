class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26];
        memset(freq, 0, 26*sizeof(int));
        int count = 0;
        for (int k = 0; s[k]; k++) {
            freq[s[k] - 'a']++;
            freq[t[k] - 'a']--;
        }
        for (int k = 0; k < 26; k++) {
            count += freq[k] > 0 ? freq[k] : 0;
        }
    return count;
    }
};