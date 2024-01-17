class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> uniqueFreqs;
        for (auto& pair : freq) {
            if (!uniqueFreqs.insert(pair.second).second) {
                return false;  // Frequency not unique
            }
        }

        return true; 
    }
};