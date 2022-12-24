class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sellingStatePrice = 0;
        int buyStatePrice = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            int new_b = 0;
            int new_s = 0;
            if(sellingStatePrice - prices[i] > buyStatePrice){
                new_b = sellingStatePrice - prices[i];
            }
            else{
                new_b = buyStatePrice;
            }

            if(buyStatePrice + prices[i] - fee > sellingStatePrice){
                new_s = buyStatePrice + prices[i] - fee;
            }
            else{
                new_s = sellingStatePrice;
            }

            buyStatePrice = new_b;
            sellingStatePrice = new_s;
        }
        return sellingStatePrice;
    }
};