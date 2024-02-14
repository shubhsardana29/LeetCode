class Solution {
public:
    vector<int>bruteforce(vector<int>& nums){
        vector<int>pos, neg;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]); 
            }
        }
        vector<int>ans;
        int i=0;
        while(i<pos.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }


    vector<int>twopointer(vector<int>& nums){
        int n= nums.size();
        vector<int>ans(n,-1);
        int even =0;
        int odd=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[even]=nums[i];
                even+=2;
            }
            else{
                ans[odd]=nums[i];
                odd+=2;
            }
        }
        return ans;
        
    }

    
    vector<int> rearrangeArray(vector<int>& nums) {
        // return bruteforce(nums);
        return twopointer(nums);
    }
};