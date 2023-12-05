class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        char ans = ' ';
        map<char, int> freq;
        queue<char> q;

        for (int i = 0; i < n; i++) {
            char letter = s[i];
            freq[letter]++;
            q.push(letter);
        }

        while (!q.empty()) {
            char letter = q.front();
            if (freq[letter] == 1) {
                ans = letter;
                break;
            } else {
                q.pop();
            }
        }

        // Find the index of the first occurrence of the unique character
        for (int i = 0; i < n; i++) {
            if (s[i] == ans) {
                return i;
            }
        }

        // If no unique character is found
        return -1;
    }
};