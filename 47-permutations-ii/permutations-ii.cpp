class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> tempList;
        vector<bool> used(nums.size(),0);
        sort(nums.begin(),nums.end());
        backtrack(list, tempList, nums, used);
        return list;
    }
    void backtrack(vector<vector<int>>& list, vector<int>& tempList, vector<int>& nums, vector<bool>&used) {
        int n = nums.size();
        if (tempList.size() == n) {
            list.push_back(tempList);
        }
        for (int i = 0; i < n; i++) {
            if((i>0 && nums[i]==nums[i-1] && !used[i-1]) || used[i]==1){
                continue;
            }
            used[i]=true;
            tempList.push_back(nums[i]);
            backtrack(list, tempList, nums, used);
            used[i]=false;
            tempList.pop_back();
        }
    }
};