class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least = INT_MAX;
        int profitSoFar = 0;
        int ans = INT_MIN;

        for(int i = 0; i < prices.size(); i++){
            if(least > prices[i]){
                least = prices[i];
            }
            profitSoFar = prices[i] - least;
            ans = max(ans, profitSoFar);
        }
        return ans;
    }
};