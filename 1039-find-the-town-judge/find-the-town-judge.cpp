// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<int> indegree(n + 1, 0); // indegree[i] represents the number of people who trust person i
//         vector<int> outdegree(n + 1, 0); // outdegree[i] represents the number of people person i trusts

//         for (const auto& relation : trust) {
//             int a = relation[0];
//             int b = relation[1];
//             outdegree[a]++;
//             indegree[b]++;
//         }

//         for (int i = 1; i <= n; ++i) {
//             if (indegree[i] == n - 1 && outdegree[i] == 0) {
//                 return i;
//             }
//         }

//         return -1; // No town judge found

//     }
//};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degrees(n + 1, 0); // Positive values represent outdegree, negative values represent indegree

        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            degrees[a]--; // Reduce outdegree for a
            degrees[b]++; // Increase indegree for b
        }

        for (int i = 1; i <= n; ++i) {
            if (degrees[i] == n - 1) {
                return i;
            }
        }

        return -1; // No town judge found
    }
};
