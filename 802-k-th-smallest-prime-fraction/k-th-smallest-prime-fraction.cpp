class Solution {
public:
    typedef pair<double, pair<int, int>> Fraction;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Fraction, vector<Fraction>, greater<Fraction>> pq;

        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            double value = double(arr[i]) / arr[n - 1];
            pq.push({value, {i, n - 1}});
        }
        
        for (int i = 0; i < k - 1; i++) {
            Fraction currentFraction = pq.top();
            pq.pop();
            
            int numeratorIndex = currentFraction.second.first;
            int denominatorIndex = currentFraction.second.second;

            if (denominatorIndex - 1 > numeratorIndex) {
                double nextValue = double(arr[numeratorIndex]) / arr[denominatorIndex - 1];
                pq.push({nextValue, {numeratorIndex, denominatorIndex - 1}});
            }
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};
