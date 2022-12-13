#include <iostream>
#include <vector>
using namespace std ;

int noOfWays(int n, int m){
    vector<int>dp(n+1);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++){
        if(i < m){
            dp[i] = 1;
        }
        else if(i == m){
            dp[i] = 2;
        }
        else{
            dp[i] = dp[i - 1] + dp[i - m];
        }
    }
    return dp[n];
}

int main() {
  int n ;
  cin >> n ;
  int m ;
  cin >> m ;
  //   write your code here
  cout << noOfWays(n, m);
  return 0;

}