class Solution {
public:
    int appendCharacters(string s, string t) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        int l = t.length();
        while (i < n && j < l) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        count = l - j;
        return count;
    }
};