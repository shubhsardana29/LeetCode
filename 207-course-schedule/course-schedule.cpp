class Solution {
private:
    // Function to return list containing vertices in Topological order.
    bool topoSort(int numCourses, vector<vector<int>>& adjList) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> inPath; // To detect cycles during DFS
        stack<int> st;

        // Call DFS for each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && !hasCycle(i, visited, inPath, adjList, st)) {
                return false; // If cycle is detected, return false
            }
        }

        // Extract the topological order from the stack
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result.size() == numCourses;
    }

    bool hasCycle(int src, unordered_map<int, bool>& visited,
                  unordered_map<int, bool>& inPath,
                  vector<vector<int>>& adjList, stack<int>& st) {
        visited[src] = true;
        inPath[src] = true;

        for (auto nbr : adjList[src]) {
            if (inPath[nbr]) {
                return false; // Cycle detected
            }
            if (!visited[nbr] && !hasCycle(nbr, visited, inPath, adjList, st)) {
                return false; // If cycle is detected in the recursive call,
                              // return false
            }
        }

        inPath[src] = false; // Mark the end of DFS path
        st.push(src);
        return true;
    }

public:
    void initializeGraph(int numCourses, vector<vector<int>>& prerequisites,
                         vector<vector<int>>& adjList) {
        for (int i = 0; i < prerequisites.size(); ++i) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        initializeGraph(numCourses, prerequisites, adjList);

        return topoSort(numCourses, adjList);
    }
};