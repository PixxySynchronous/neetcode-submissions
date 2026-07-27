class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //for optimum approach what we do is, maintain a minimum price var
        //calculate profit by doing curr elem - minprice AND maintain highest profit. 
        //if profit<0 , return 0 
        int minPrice = INT_MAX;
        int profit = 0; 
        for (int i = 0 ; i<prices.size(); i++){
            if (prices[i] < minPrice)     
                minPrice = prices[i]; 
            profit = max (profit, prices[i] - minPrice); 
        }
        if (profit < 0) return 0; 
        return profit; 
    }
};
