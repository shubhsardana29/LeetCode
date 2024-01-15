class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>win,lose;
        for(int i=0; i<matches.size(); i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        vector<int>v1,v2;
        for(auto it:win){
            if(lose.count(it.first)==0){
                v1.push_back(it.first);
            }
        }
        for(auto it:lose){
            if(it.second==1){
                v2.push_back(it.first);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        //in place of sort function we can directly use map instead of unorderd map
        return {v1,v2};
    }
};