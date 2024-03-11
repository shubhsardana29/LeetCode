class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        for (int j = 0; j < order.size(); j++) {
            char current = order[j];
            size_t found = s.find(current);
            while (found != string::npos) {
                ans.push_back(current);
                found = s.find(current, found + 1);
            }
        }

        // Append the remaining characters from s
        for (char c : s) {
            if (order.find(c) == string::npos) {
                ans.push_back(c);
            }
        }

        return ans;
    }
};