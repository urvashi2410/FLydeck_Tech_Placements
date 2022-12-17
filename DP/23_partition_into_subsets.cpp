#include <iostream> 
#include <vector>
using namespace std;

int partition(int n, int k){
    vector<vector<int>>dp(n+1, vector<int>(k+1));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else if(i < j){
                dp[i][j] = 0;
            }
            else if(i > j){
                dp[i][j] = dp[i-1][j] * j + dp[i-1][j-1];
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n ;
    cin>>n ;
    int k ;
    cin>>k ;

    // write your code here
    cout << partition(n, k);
}