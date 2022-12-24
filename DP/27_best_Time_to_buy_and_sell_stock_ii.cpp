class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int s = 0;
        int b = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] >= prices[i-1]){
                s++;
            }
            else{
                profit += (prices[s] - prices[b]);
                b = i;
                s = i;
            }
        }

        profit += (prices[s] - prices[b]);
        return profit;
    }
};