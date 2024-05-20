class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(list,1,tempList,n,k);
        return list;
    }
    void backtrack(vector<vector<int>>&list,int start,vector<int>&tempList,int n, int k){
        if (tempList.size() == k) {
            list.push_back(tempList);
        }
        for(int i=start;i<=n;i++){
            tempList.push_back(i);
            backtrack(list,i+1,tempList,n,k);
            tempList.pop_back();
        }
    }
};