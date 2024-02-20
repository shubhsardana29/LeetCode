class Solution {
public:
    int bruteforce(vector<int>& nums){
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int totalSum=(n*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }

    int bs_sol(vector<int>& nums){
        int s=0;
        int n = nums.size();
        int e=n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        
        while(s<=e){
            if(nums[mid]-mid == 1){
                // right m jao
                s = mid+1;
            }
            else{
                // ans store
                ans = mid;
                // left m jao
                e = mid -1;
            }
            mid = s+ (e-s)/2;
        }
        if(ans+1==0) {
            return n+1;
        } 
        return ans + 1;
    }

    int missingNumber(vector<int>& nums) {
        return bruteforce(nums);
        // return bs_sol(nums);
    }
};