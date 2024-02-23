class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);  
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> distance(n, INT_MAX);  
        // {stops,{distance,node}}
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {0, src}});
        distance[src] = 0;

        // distance updation logic
        while (!st.empty()) {
            auto topElement = st.begin();
            pair<int, pair<int, int>> topPair = *topElement;
            int topStops = topPair.first;
            int topDist = topPair.second.first;
            int topNode = topPair.second.second;

            st.erase(topElement);  // Remove the processed element

            if (topStops > k)
                continue;

            // update distance of nbr
            for (pair<int, int> nbrPair : adj[topNode]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (topDist + nbrDist < distance[nbrNode] && topStops <= k) {  
                    distance[nbrNode] = topDist + nbrDist;  
                    st.insert({topStops + 1, {distance[nbrNode], nbrNode}});  
                }
            }
        }

        if (distance[dst] == INT_MAX)
            return -1;

        return distance[dst];
    }
};