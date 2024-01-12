class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.length() / 2;
        int vowelCount1 = 0, vowelCount2 = 0;

        for (int i = 0; i < n; i++) {
            if (vowels.find(s[i]) != string::npos) {
                vowelCount1++;
            }
            if (vowels.find(s[i + n]) != string::npos) {
                vowelCount2++;
            }
        }

        return vowelCount1 == vowelCount2;
    }
};
