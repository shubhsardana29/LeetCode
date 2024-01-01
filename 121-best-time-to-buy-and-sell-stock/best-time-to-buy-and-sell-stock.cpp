class Solution {
public:
    int iterativeSol(vector<int>& prices){
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
    void maxProfitFinder(vector<int>& prices,int i,int &minPrice , int &maxProfit){
        //base case
        if(i==prices.size()) return;
        // one case
        if(prices[i]<minPrice) minPrice = prices[i];
        int todaysProfit = prices[i] - minPrice;
        if(todaysProfit > maxProfit) maxProfit = todaysProfit;

        // recursion will handle rest cases
        maxProfitFinder(prices,i+1,minPrice,maxProfit);


    }
    int recursiveSol(vector<int>& prices){
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        maxProfitFinder(prices,0,minPrice,maxProfit);
        
        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        // return iterativeSol(prices);
        return recursiveSol(prices);
    }
};