class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();

                int result = performOperation(operand1, operand2, token);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int performOperation(int operand1, int operand2, const string& op) {
        if (op == "+") {
            return operand1 + operand2;
        } else if (op == "-") {
            return operand1 - operand2;
        } else if (op == "*") {
            return operand1 * operand2;
        } else if (op == "/") {
            return operand1 / operand2;
        }
        return 0;
    }
};
