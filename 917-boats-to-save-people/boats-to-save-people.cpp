class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        
        sort(nums.begin(),nums.end());
        int count=0;
        int i=nums.size()-1;
        while(i>=0 && nums[i]==limit)
        {
            count++;
            i--;
        }
        int left=0,right=i;
        while(left<=right)
        {
            if(left==right) 
            {
                count++;
                break;
            }
            int sum=nums[left]+nums[right];
            if(sum>limit)
            {
                right--;
                count++;
            }
            else
            {
                left++;
                right--;
                count++;
            }
        }
        return count;
    }
};