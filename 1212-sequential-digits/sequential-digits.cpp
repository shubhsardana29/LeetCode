class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int startDigit = 1; startDigit <= 9; ++startDigit) {
            generateSequentialDigits(ans, low, high, 0, startDigit);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    void generateSequentialDigits(vector<int>& ans, int low, int high, int current, int digit) {
        if (current > high) {
            return;
        }

        if (current >= low && current <= high) {
            ans.push_back(current);
        }

        if (digit <= 9 && current * 10 + digit <= high) {
            generateSequentialDigits(ans, low, high, current * 10 + digit, digit + 1);
        }
    }
};


// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int>ans;
//         vector<int> possible = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};
//         for(int i = 0; i < possible.size(); i++) {
//             if(low <= possible[i] && high >= possible[i]) {
//                 ans.push_back(possible[i]);
//             }
//         }

//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> ans;

//         string digits = "123456789";
//         int n = digits.size();

//         for (int len = 1; len <= n; ++len) {
//             for (int i = 0; i <= n - len; ++i) {
//                 string sub = digits.substr(i, len);
//                 int num = stoi(sub);
//                 if (num >= low && num <= high) {
//                     ans.push_back(num);
//                 }
//             }
//         }

//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };