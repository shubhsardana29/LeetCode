class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int curr = temperatures[i];

            // Pop elements from the stack until you find a greater temperature
            while (!st.empty() && temperatures[st.top()] <= curr) {
                st.pop();
            }

            // If the stack is not empty, update the answer
            ans[i] = (st.empty()) ? 0 : (st.top() - i);

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }
};