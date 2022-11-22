#include <bits/stdc++.h>
using namespace std;

bool targetSubsetSum(int A[], int n, int tar){
    vector<vector<int>> dp(n+1, vector<int>(tar+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= tar; j++){
            // as empty set will make sum of 0 
            if(i == 0 && j == 0){
                return true;
            }
            // as empty set cannot make any other number than 0 
            else if(i == 0){
                return false;
            }
            // as every number can make 0 by not including in it 
            else if(j == 0){
                return true;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= tar; j++){
            if(j >= A[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][tar];
}

int main(){
    int n;
    cin >> n;
    int A[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }

    if(sum % 2 == 0){
        cout << targetSubsetSum(A, n, sum/2);
    }
    else{
        cout << "false";
    }
}