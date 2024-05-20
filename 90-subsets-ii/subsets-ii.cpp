class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>list;
        vector<int>tempList;
        sort(nums.begin(),nums.end());
        backtrack(list,tempList,nums,0);
        return list;
    }
    void backtrack(vector<vector<int>>&list,vector<int>&tempList,vector<int>& nums,int start){
        list.push_back(tempList);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            tempList.push_back(nums[i]);
            backtrack(list,tempList,nums,i+1);
            tempList.pop_back();
        }
    }
};