class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> freq; // Frequency map for the first word
        for (char c : words[0]) {
            freq[c]++;
        }
        
        // Update the frequency map based on subsequent words
        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> tempFreq;
            for (char c : words[i]) {
                tempFreq[c]++;
            }
            // Update the freq map to store the minimum frequencies
            for (auto& entry : freq) {
                entry.second = min(entry.second, tempFreq[entry.first]);
            }
        }
        
        vector<string> result;
        // Collect the common characters based on the minimum frequency
        for (auto& entry : freq) {
            for (int i = 0; i < entry.second; i++) {
                result.push_back(string(1, entry.first));
            }
        }
        
        return result;
    }
};