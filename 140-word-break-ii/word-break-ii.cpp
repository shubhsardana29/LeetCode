class Solution {
public:
    unordered_set<string> st;
    vector<string> result;   
    string currSentence = "";

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Populate the set with dictionary words
        for (string& word : wordDict) {
            st.insert(word);
        }
        
        // Start the recursive solution
        solve(0, currSentence, s);
        return result;
    }

    void solve(int i, string& currSentence, string& s) {
        // If we've reached the end of the string, add the current sentence to the result
        if (i == s.length()) {
            result.push_back(currSentence);
            return;
        }
       
        for (int j = i; j < s.length(); j++) {
            string tempWord = s.substr(i, j - i + 1);
            if (st.count(tempWord)) { // Check if tempWord is a valid word
                string tempSentence = currSentence;
                if (!currSentence.empty()) {
                    currSentence += " ";
                }
                currSentence += tempWord; // Add tempWord to the current sentence
                solve(j + 1, currSentence, s); // Recur with the next index
                currSentence = tempSentence; // Backtrack to the previous state
            }
        }
    }
};
