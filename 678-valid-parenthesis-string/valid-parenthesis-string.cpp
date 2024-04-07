class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_st; // Store indices of '(' and '*'
        stack<int> star_st; // Store indices of '*'

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left_st.push(i);
            } else if (s[i] == '*') {
                star_st.push(i);
            } else { // When encountering ')'
                if (!left_st.empty()) {
                    left_st.pop(); // Matching '(' found
                } else if (!star_st.empty()) {
                    star_st.pop(); // Treat '*' as '('
                } else {
                    return false; // No matching '(' or '*' found
                }
            }
        }

        // Match remaining '(' with '*'
        while (!left_st.empty() && !star_st.empty()) {
            if (left_st.top() > star_st.top()) {
                return false; // '*' occurs before '('
            }
            left_st.pop();
            star_st.pop();
        }

        return left_st.empty(); // All '(' are matched
    }
};