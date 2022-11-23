#include<bits/stdc++.h>
using namespace std;
int min_jumps(int A[], int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    for(int i=(n-1);i>=0;i--) {
        if(A[i]>0) {
            int minimum = INT_MAX;
            for(int j=1;j<=A[i];j++) {
                minimum = min(minimum, dp[i+j]);
            }
            if(minimum!=INT_MAX) {
                dp[i] = minimum + 1;
            }
            else {
                dp[i] = 0;
            }
        }
    }
    return dp[0];
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<min_jumps(A, n)<<endl;
    return 0;
}