class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);

        if(n==1) return {0};

        for (auto& edges : edges) {
            int u = edges[0];
            int v = edges[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1) q.push(i);
        }
        while(n > 2) {
            int size = q.size();
            n -= size; //removing nodes with indegreee 1
            
            while(size--) {
                int u = q.front();
                q.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        q.push(v);
                }
            }
        }
        
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};