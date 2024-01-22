class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n=nums.size();
        int repeat,missing;
        int actualSumFormula = (int)(n * (n+1))/2;
        int observedSum = 0;
        for(int i=0;i<n;i++){
            observedSum += abs(nums[i]);
            if(nums[abs(nums[i])-1]<0) repeat = abs(nums[i]);
            else nums[abs(nums[i])-1] *= -1;
        }
        missing = actualSumFormula + repeat - observedSum;
        
        return {repeat,missing};
        
    }
};