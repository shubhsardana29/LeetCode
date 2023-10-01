class Solution {
public:
    int bruteforce(vector<int>& nums){
    int n = nums.size();
        for(int i=0;i<n;i++){
        int right_sum=0;
        int left_sum=0;

            for(int j=0;j<i;j++){
                left_sum+= nums[j];
            }
            for(int j=i+1;j<n;j++){
                right_sum+= nums[j];
            }
            if(left_sum == right_sum){
                return i;
            }

        }
        return -1;
    }

    int prefixSumApproach(vector<int>& nums){
    int n = nums.size();
        vector<int>lsum(n,0);
        vector<int>rsum(n,0);

        // calc left sum array
        for(int i=1;i<n;i++){
            lsum[i]=lsum[i-1]+nums[i-1];
        }
        // calc right sum array
        for(int i=n-2;i>=0;i--){
            rsum[i]=rsum[i+1]+nums[i+1];
        }
        //check karte hai
        for(int i=0;i<n;i++){
            if(lsum[i]==rsum[i]) return i;
        }
        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
    }
};