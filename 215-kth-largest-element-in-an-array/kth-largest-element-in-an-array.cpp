class Solution {
public:
// using min heap
    int minHeap(vector<int>& nums,int n,int k){
        priority_queue<int,vector<int>,greater<int>>pq;
        // first k elements ko process karo
        for(int i=0;i<k;i++){
            int element= nums[i];
            pq.push(element);
        }
        //remaining element ko tabhi process karenge jab wo root se chote honge
        for(int i=k;i<n;i++){
            int remainingElement= nums[i];
            if(remainingElement>pq.top()){
                // pq.top()=remaingElement;
                pq.pop();
                pq.push(remainingElement);
            }
        }
        int ans = pq.top();
        return ans;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n= nums.size();
        return minHeap(nums,n,k);
    }
};