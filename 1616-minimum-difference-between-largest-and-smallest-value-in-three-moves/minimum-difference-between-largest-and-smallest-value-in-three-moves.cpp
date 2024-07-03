class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<5) return 0;
        sort(nums.begin(),nums.end());
        int a,b;
        //4 cases
        //Take 1 element from start and 2 element from end
        // Take 2 element from start and 1 element from end
        // Take 3 element from start and 0 element from end
        // Take 0 element from start and 3 element from end
        int ans = INT_MAX;
        int n=nums.size();

        //case one (start-1, end-2)
        a = nums[1];
        b = nums[n-3];
        ans = min(ans, b-a);

        //case 2 (s-2, e-1)
        a = nums[2];
        b = nums[n-2];
        ans = min(ans, b-a);

        //case 3 (s-3, e-0)
        a = nums[3];
        b = nums[n-1];
        ans = min(ans, b-a);

        //case 4 (s-0, e-3)
        a = nums[0];
        b = nums[n-4];
        ans = min(ans, b-a);

        return ans;

    }
};