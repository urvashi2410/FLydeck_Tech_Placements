class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sellingStatePrice = 0;
        int buyStatePrice = -prices[0];
        int coolStatePrice = 0;

        for(int i = 1; i < prices.size(); i++){
            int new_b = 0;
            int new_s = 0;
            int new_c = 0;

            if(coolStatePrice - prices[i] > buyStatePrice){
                new_b = coolStatePrice - prices[i];
            }
            else{
                new_b = buyStatePrice;
            }

            if(buyStatePrice + prices[i] > sellingStatePrice){
                new_s = buyStatePrice + prices[i];
            }
            else{
                new_s = sellingStatePrice;
            }

            if(coolStatePrice < sellingStatePrice){
                new_c = sellingStatePrice;
            }
            else{
                new_c = coolStatePrice;
            }

            
            buyStatePrice = new_b;
            sellingStatePrice = new_s;
            coolStatePrice = new_c;
        }
        return max(coolStatePrice, sellingStatePrice);
    }
};