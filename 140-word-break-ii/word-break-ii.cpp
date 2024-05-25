class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end()); 
        vector<string> result;
        string currSentence = "";
        
        solve(0, currSentence, s, st, result);
        return result;
    }

private:
    void solve(int i, string currSentence, string& s, unordered_set<string>& st, vector<string>& result) {
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
                solve(j + 1, currSentence, s, st, result); // Recur with the next index
                currSentence = tempSentence; // Backtrack to the previous state
            }
        }
    }
};
