class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            if ((s.back() - '0') & 1) {
                // The number is odd if the last bit is '1'
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            } else {
                // The number is even if the last bit is '0'
                s.pop_back();
            }
            steps++;
        }

        return steps;
    }
};
