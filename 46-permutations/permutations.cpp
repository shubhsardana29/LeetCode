class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> tempList;
        vector<bool> used(nums.size(),0);
        backtrack(list, tempList, nums, used);
        return list;
    }
    void backtrack(vector<vector<int>>& list, vector<int>& tempList, vector<int>& nums, vector<bool>&used) {
        int n = nums.size();
        if (tempList.size() == n) {
            list.push_back(tempList);
        }
        for (int i = 0; i < n; i++) {
            if(used[i]==1) continue;
            used[i]=true;
            tempList.push_back(nums[i]);
            backtrack(list, tempList, nums, used);
            used[i]=false;
            tempList.pop_back();
        }
    }
};