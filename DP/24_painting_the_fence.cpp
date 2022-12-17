long long countWays(int n, int k){
        // code here
        long long mod = 1000000007;
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return k;
        }
        else{
            long long same = k;
            long long diff = k * (k-1);
            for(long long i = 3; i <= n; i++){
                long long total = (same + diff) % mod;
                same = diff % mod;
                diff = total * (k-1);
            }
            return (same + diff) % mod;
        }
    }