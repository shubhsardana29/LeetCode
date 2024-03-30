class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return findAtMostK(n, k, nums) - findAtMostK(n, k-1, nums);
    }

    int findAtMostK(int n, int k, vector<int>&nums){
        int ans = 0;
        int left = 0, right = 0;
        unordered_map<int, int>mp;
        while(right<n){
            if(mp.find(nums[right])==mp.end()){
                mp[nums[right]] = 1;
            }
            else{
                mp[nums[right]]++;
            }

            while(mp.size()> k && left<=right){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }
};
