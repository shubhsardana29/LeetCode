class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());
        
        // Step 2: Perform k operations
        while (k > 0) {
            // Get the top element from the max heap
            int top = pq.top();
            pq.pop();
            
            // Calculate the processed value after the operation
            int processed = top - top / 2;
            
            // Push the processed value back to the max heap
            pq.push(processed);
            
            // Decrement k
            k--;
        }
        // Step 3: Calculate the sum of the remaining pile sizes
        int result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
        
        return result;
    
    }
};