class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>result(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[score[i]]=i;
        }
        sort(score.begin(),score.end(),greater<int>());

        for (int i = 0; i < n; i++) {
            int ath = mp[score[i]];
            if (i == 0) {
                result[ath] = "Gold Medal";
            } else if (i == 1) {
                result[ath] = "Silver Medal";
            } else if (i == 2) {
                result[ath] = "Bronze Medal";
            } else {
                result[ath] = to_string(i + 1);
            }
        }
        
        return result;
    }
};