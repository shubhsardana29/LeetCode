class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        char element;
        map<char, int> freqMap;

        // Count the frequency of each character
        for (int i = 0; i < s.size(); i++) {
            element = s[i];
            freqMap[element]++;
        }

        // Create a vector of pairs (character, frequency) for sorting
        vector<pair<char, int>> charFrequencyVec(freqMap.begin(), freqMap.end());

        // Sort the vector based on frequency in descending order
        sort(charFrequencyVec.begin(), charFrequencyVec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        // Construct the result string based on the sorted characters and their frequencies
        for (const auto& pair : charFrequencyVec) {
            ans += string(pair.second, pair.first);
        }

        return ans;
    }
};