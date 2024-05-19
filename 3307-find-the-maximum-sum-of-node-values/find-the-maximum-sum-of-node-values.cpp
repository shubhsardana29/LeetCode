class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0, incCount=0, sacrifice = INT_MAX;
        for(auto el:nums){
            if((el^k)>el){
                sum+=el^k;
                sacrifice=min(sacrifice,(long long)(el^k)-el);
                incCount++;
            }
            else{
                sum+=el;
                sacrifice=min(sacrifice,(long long)(el - (el^k)));
            }
        }
        if(incCount % 2 == 0){
            return sum;
        }
        return sum - sacrifice;
    }
};