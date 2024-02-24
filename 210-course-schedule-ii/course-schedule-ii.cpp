class Solution {
private:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int numCourses, vector<vector<int>>& adjList) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> inStack;  // to detect cycles
        stack<int> st;

        // Call DFS for each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (!topoSortUsingDFS(i, visited, inStack, st, adjList)) {
                    return {};  // Cycle detected
                }
            }
        }

        // Extract the topological order from the stack
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }

    bool topoSortUsingDFS(int src, unordered_map<int, bool>& visited, unordered_map<int, bool>& inStack,
                          stack<int>& st, vector<vector<int>>& adjList) {
        visited[src] = true;
        inStack[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                if (!topoSortUsingDFS(nbr, visited, inStack, st, adjList)) {
                    return false;  // Cycle detected
                }
            } else if (inStack[nbr]) {
                return false;  // Cycle detected
            }
        }

        inStack[src] = false;
        st.push(src);
        return true;
    }

public:
    void initializeGraph(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& adjList) {
        for (int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        initializeGraph(numCourses, prerequisites, adjList);

        vector<int> ans = topoSort(numCourses, adjList);
        return ans;
    }
};
