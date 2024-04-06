class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        string ans = "";
        stack<int> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i]) || s[i] == '(') {
                ans += s[i];
                if (s[i] == '(') {
                    st.push(ans.size() - 1); // Store the index of '(' in the ans string
                }
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Matching '(' found, pop from stack
                    ans += s[i];
                }
            }
        }

        // Remove unmatched '(' indices from ans
        while (!st.empty()) {
            ans.erase(ans.begin() + st.top());
            st.pop();
        }
        
        return ans;
    }
};