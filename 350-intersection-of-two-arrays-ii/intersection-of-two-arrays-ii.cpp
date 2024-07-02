class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto j:nums2){
            mp2[j]++;
        }
        vector<int> result;
        // Iterate through the first map and find the minimum count of each element in both maps
        for (const auto& entry : mp1) {
            int element = entry.first;
            int count1 = entry.second;
            int count2 = mp2[element];
            int minCount = min(count1, count2);

        for (int i = 0; i < minCount; ++i) {
            result.push_back(element);
        }
    }

    return result;
        
    }
};