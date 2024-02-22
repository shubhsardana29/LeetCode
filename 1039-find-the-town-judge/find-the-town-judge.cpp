class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0); // indegree[i] represents the number of people who trust person i
        vector<int> outdegree(n + 1, 0); // outdegree[i] represents the number of people person i trusts

        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            outdegree[a]++;
            indegree[b]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1; // No town judge found

    }
};