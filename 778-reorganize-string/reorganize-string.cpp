class Solution {
public:
    // method 1: using max heap
    string methodUsingHeap(string &s) {
        unordered_map<char, int> charCountMap;
        priority_queue<pair<int, char>> pq;  // store frequency first

        // Step 2: Update the character count map
        for (int i = 0; i < s.size(); i++) {
            charCountMap[s[i]]++;
        }

        // Step 3: Push pairs into the max heap
        for (auto entry : charCountMap) {
            pq.push({entry.second, entry.first});
        }

        // Step 4: Reconstruct the string
        string result = "";
        while (pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();

            // Append the characters to the result
            result += first.second;
            result += second.second;

            // Decrement the frequencies and push back if not zero
            if (--first.first > 0) {
                pq.push(first);
            }
            if (--second.first > 0) {
                pq.push(second);
            }
        }

        // If there's one character left in the heap, append it to the result
        if (!pq.empty()) {
            auto last = pq.top();
            if (last.first > 1) {
                return "";  // It's not possible to reconstruct the string without adjacent identical characters
            }
            result += last.second;
        }

        return result.size() == s.size() ? result : "";  // Check if it's possible to reconstruct the string
    }

    string reorganizeString(string s) {
        return methodUsingHeap(s);
    }
};
