class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(begin(nums1),end(nums1));
        vector<int>ans;
        for(int i:nums2){
            if(st.find(i)!=st.end() && find(ans.begin(), ans.end(), i) == ans.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};