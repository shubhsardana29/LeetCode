class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        map<char, int> freq;
        queue<char> q;

        for (int i = 0; i < n; i++) {
            char letter = s[i];
            freq[letter-'a']++;
            q.push(letter);
        }

        while (!q.empty()) {
            char letter = q.front();
            if (freq[letter-'a'] == 1) {
                // Return the index of the first non-repeating character
                return s.find(letter);

            } else {
                q.pop();
            }
        }

         // If no unique character is found
        return -1;
    }
};