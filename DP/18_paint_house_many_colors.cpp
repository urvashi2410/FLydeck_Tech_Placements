#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, colors;
    cin >> n >> colors;
    
    int arr[n][colors];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < colors; j++){
            cin >> arr[i][j];
        }
    }
    
    int dp[n][colors];
    
    // pehle ghr me saare color daalke dekhe 
    for(int j = 0; j < colors; j++){
        dp[0][j] = arr[0][j];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < colors; j++){
            int minimum  = INT_MAX;
            
            for(int k = 0; k < colors; k++){
                if(k != j){
                    if(dp[i - 1][k] < minimum){
                        minimum = dp[i - 1][k];
                    }
                }
            }
            dp[i][j] = arr[i][j] + minimum;
        }
    }
    
    int minimum = INT_MAX;
    for(int k = 0; k < colors; k++){
        if(dp[n - 1][k] < minimum){
            minimum = dp[n - 1][k];
        }
    }
    
    cout << minimum << endl;
}