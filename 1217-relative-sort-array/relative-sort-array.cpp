  class Solution {
public:
    // Define the type of the lambda function
    using Comparator = function<bool(int, int)>;

    // Define the lambda function as a class member
    Comparator cmpr = [](int a, int b)
    {
        return a < b;
    };

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> numPosMap;
        for (int i = 0; i < arr2.size(); i++) {
            numPosMap[arr2[i]] = i + 1;
        }
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (numPosMap.count(a) && numPosMap.count(b)) {
                return numPosMap[a] < numPosMap[b];
            } else if (numPosMap.count(a)) {
                return true;
            } else if (numPosMap.count(b)) {
                return false;
            } else {
                return a < b;
            }
        });
        
        return arr1;
    }
};
