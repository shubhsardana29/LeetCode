class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(list,tempList,nums,0);
        return list;
    }
    void backtrack(vector<vector<int>>&list,vector<int>&tempList,vector<int>& nums,int start){
        list.push_back(tempList);
        for(int i=start;i<nums.size();i++){
            tempList.push_back(nums[i]);
            backtrack(list,tempList,nums,i+1);
            tempList.pop_back();
        }
    }
};