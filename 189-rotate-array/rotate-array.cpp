class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int>res(nums);
        // int n=nums.size();
        // k=k%nums.size();
        // for(int i=0;i<n;i++){
        //     res[(i + k) % n] = nums[i];
        // }
        // nums=res;

        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};