class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++; 
        }
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};