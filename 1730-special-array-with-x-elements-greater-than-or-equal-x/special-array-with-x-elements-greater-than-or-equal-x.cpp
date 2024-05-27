class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=count){
                count++;
                if(count>nums[i]) return -1;
            }
            else{
                return count;
            }
        }
        return n;
    }
};