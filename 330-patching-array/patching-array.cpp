class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count=0,i=0;
        long range=0;
        while(range<n){
            if(i>=nums.size() || nums[i]>(range+1) ){
                range += range+1;
                count++;
            }
            else if(i<nums.size() && nums[i]<=(range+1)){ 
                range += nums[i];
                i++;
            }
        }
        return count;
    }
};