#include<bits/stdc++.h>
using namespace std;

int paintHouse(vector<vector<int>>costs){
    int ans = INT_MAX;
    vector<vector<int>>dp(costs.size(), vector<int>(3));
    for(int i = 0; i < costs.size(); i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = costs[i][j];
        }
    }

    for(int i = 1; i < costs.size(); i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
    }

    ans = min(dp[costs.size()-1][0], min(dp[costs.size()-1][1], dp[costs.size()-1][2]));
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>costs(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> costs[i][j];
        }
    }
    cout << paintHouse(costs);
    return 0;
}