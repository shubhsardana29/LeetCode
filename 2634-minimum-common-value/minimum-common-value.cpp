class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(begin(nums1),end(nums1));
        for(int i:nums2){
            if(st.find(i)!=st.end()){
                return i;
            }
        }
        return -1;
    }
};