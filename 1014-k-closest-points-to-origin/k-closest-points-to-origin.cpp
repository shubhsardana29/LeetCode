class compare{
public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        int distA = pow(a.first,2)+pow(a.second,2);
        int distB = pow(b.first,2)+pow(b.second,2);
        return distA>distB;
    }    
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare >pq;

        for(auto p:points){
            pq.push({p[0],p[1]});
        }
        while(!pq.empty() && k--){
            pair<int,int>top = pq.top();
            ans.push_back({top.first,top.second});
            pq.pop();
        }

        return ans;
    }
};