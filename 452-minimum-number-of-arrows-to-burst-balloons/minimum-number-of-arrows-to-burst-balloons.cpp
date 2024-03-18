class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort points based on end points using the compare function
        sort(points.begin(), points.end(), compare);

        int numArrowShots = 0;
        int i = 0;

        while (i < points.size()) {
            numArrowShots++;
            int endMaxVal = points[i][1];

            while (i < points.size() &&
                   (endMaxVal <= points[i][1] && endMaxVal >= points[i][0])) {
                i++;
            }
        }

        return numArrowShots;
    }
};
