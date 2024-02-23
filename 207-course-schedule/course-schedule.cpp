class Solution {
private:
    vector<int> topoSort(int numCourses, vector<vector<int>>& adjList) {
        vector<int> order;
        vector<int> visited(numCourses, 0);  // 0: not visited, 1: visiting, 2: visited

        stack<int> st;
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && !topoSortUsingDFS(i, visited, st, adjList, order)) {
                return {};  // Return empty vector if a cycle is detected
            }
        }

        reverse(order.begin(), order.end());  // Reverse to get the topological order
        return order;
    }

    bool topoSortUsingDFS(int src, vector<int>& visited, stack<int>& st, vector<vector<int>>& adjList, vector<int>& order) {
        visited[src] = 1;

        for (int nbr : adjList[src]) {
            if (visited[nbr] == 1 || (!visited[nbr] && !topoSortUsingDFS(nbr, visited, st, adjList, order))) {
                return false;  // Cycle detected
            }
        }

        visited[src] = 2;
        st.push(src);
        order.push_back(src);

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (const auto& prerequisite : prerequisites) {
            adjList[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<int> order = topoSort(numCourses, adjList);

        return !order.empty();  // If the order is empty, a cycle was detected
    }
};