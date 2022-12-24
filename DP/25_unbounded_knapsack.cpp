class Solution{
public:
    int knapSack(int n, int tar, int val[], int wt[])
    {
        // code here
        int dp[n + 1][tar + 1];

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= tar; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= tar; j++){
                if(j >= wt[i-1]){
                    dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j - wt[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][tar];
    }
};