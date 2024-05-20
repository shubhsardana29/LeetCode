class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(list,tempList,candidates,target,0);
        return list;
    }
    void backtrack(vector<vector<int>>&list,vector<int>&tempList,vector<int>& candidates,int remaining, int start){
        if (remaining<0) {
            return;
        }
        else if(remaining==0){
            list.push_back(tempList);
        }
        else{
            for(int i=start;i<candidates.size();i++){
                tempList.push_back(candidates[i]);
                backtrack(list,tempList,candidates,remaining-candidates[i],i);
                tempList.pop_back();
            }
        }
    }
};