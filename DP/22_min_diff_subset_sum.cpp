bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int arrSum = 0;
        
        int m = sum;
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, false));
        for(int i = 0; i < n; i++){
            arrSum += arr[i];
        }
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = false;
                }
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(j >= arr[i-1]){
                    dp[i][j] = dp[i - 1][j] || dp[i-1][j - arr[i-1]]; 
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
        
        int ans = INT_MAX;
        int j = arrSum;
        while(j >= 0){
            if(dp[n][j] == true){
                ans = min(ans, sum - 2*j);
            }
            j--;
        }
        return ans;
    }