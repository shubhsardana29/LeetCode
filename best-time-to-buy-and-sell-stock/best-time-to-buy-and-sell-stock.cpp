class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int boughtPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            int currPrice = prices[i];
            
            if(currPrice < boughtPrice) {
                boughtPrice = currPrice;
                continue;
            }
            // curr price is greater
            // time to sell
            profit = max(profit, currPrice - boughtPrice);
        }
        return profit;
    }
};