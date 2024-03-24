class Solution {
public:
    int bruteforce(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }

    // visited solution
    int vsol(vector<int>& nums){
        int n = nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int index = abs(nums[i]);

            // already visited
            if(nums[index]<0){
                ans = index;
                break;
            }
            // marking visited
            nums[index] *= -1;
        }
        return ans;
    }
    // without modifying array solution
    int swapsol(vector<int>& nums){
        int index=nums[0];
        while(index!=nums[index]){
            swap(index,nums[index]);
        }
        return index;
    }

    int findDuplicate(vector<int>& nums) {
        // return bruteforce(nums);
        // return vsol(nums);
        return swapsol(nums);
    }
};