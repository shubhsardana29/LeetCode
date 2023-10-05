class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target){
         int s=0;
       int n = nums.size();
       int e = n-1; 
       int mid= s+(e-s)/2;
       int ans = -1;
       while(s<=e){
           if(nums[mid]==target){
               // store ans
                ans = mid;
               // left m jao - to find first occurence
               e = mid-1;
           }
           else if(nums[mid]<=target){
               // right m jao 
               s = mid+1;
           }
           else if(nums[mid]>=target){
               e = mid -1;
           }
           mid = s + (e-s)/2;
       }
       return ans;
    }
    int lastOccurrence(vector<int>& nums, int target){
         int s=0;
       int n = nums.size();
       int e = n-1; 
       int mid= s+(e-s)/2;
       int ans = -1;
       while(s<=e){
           if(nums[mid]==target){
               // store ans
                ans = mid;
               // right m jao - to find last occurence
               s = mid+1;
           }
           else if(nums[mid]<=target){
               // right m jao 
               s = mid+1;
           }
           else if(nums[mid]>=target){
               e = mid -1;
           }
           
           mid = s + (e-s)/2;
       }
       return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       return {firstOccurrence(nums,target),lastOccurrence(nums,target)};
    }
};