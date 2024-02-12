class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freqMap;
        for(auto num:nums){
            freqMap[num]++;
        };
        for(int i=0;i<n;i++){
            if(freqMap[nums[i]]>n/2) return nums[i];
        }
        return -1;

        
    }
};