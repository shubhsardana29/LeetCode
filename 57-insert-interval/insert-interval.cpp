class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            // current interval can be merged with last ans interval
            int siz = ans.size();
            if (siz != 0 && ans[siz - 1][1] >= intervals[i][0]) {
                ans[siz - 1][1] = max(ans[siz - 1][1], intervals[i][1]);
                continue;
            }
            // newInterval complete dis-joint with current interval
            if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
                continue;
            }
            if (intervals[i][0] > newInterval[1]) {
                if (!inserted) ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                inserted = true;
                continue;
            }

            // newInterval overlapping with current interval
            ans.push_back({min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])});
            inserted = true;
        }
        // still not inserted
        if (!inserted) ans.push_back(newInterval);
        return ans;
    }
};