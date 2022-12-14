int countFriendsPairings(int n){ 
        // code here
    long long mod = 1000000007;
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
        
    for(long long i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + (i-1)*dp[i-2]) % mod;
    }
    return dp[n];
}