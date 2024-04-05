class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;
        
        for (char c : s) {
            if (!stack.empty() && abs(c - stack.top()) == 32) {
                stack.pop(); // Remove the last character from the stack
            } else {
                stack.push(c); // Otherwise, add the current character to the stack
            }
        }
        
        string good = "";
        while (!stack.empty()) {
            good = stack.top() + good; // Construct the resulting string in reverse order
            stack.pop();
        }
        
        return good;
    }
};