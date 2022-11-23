#include<bits/stdc++.h>
using namespace std;
bool targetSum(int A[], int n, int target) {
    bool dp[1+n][1+target];
    for(int j=0;j<=target;j++) {
        dp[0][j] = false;
    }
    for(int i=0;i<=n;i++) {
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=target;j++) {
            if(j>=A[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

bool count_subset_with_given_difference(int A[], int n, int diff) {
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += A[i];
    }
    int subset = (diff+sum)/2;
    return targetSum(A, n, subset);
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int diff;
    cin >> diff;
    cout << count_subset_with_given_difference(A, n, diff);
    return 0;
}