class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int>freq;
        for(auto num:nums){
            freq[num]++;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==1){
                sum+=nums[i];
            }
        }
        return sum;
    }
};