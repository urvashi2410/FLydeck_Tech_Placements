#include<bits/stdc++.h>
using namespace std;

int slidingWindow(vector<int>arr, int n, int k){
    int i = 0;
    int ans = INT_MIN;
    int sum = 0;
    int j;
    for(j = 0; j < k; j++){
        sum += arr[j];
    }

    while(j < n){
        ans = max(ans, sum);
        sum -= arr[j];
        i++;
        j++;
        sum += arr[j];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;
    cout << slidingWindow(arr, n, k);
    return 0;
}