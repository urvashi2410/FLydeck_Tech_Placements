#include <iostream>
using namespace std;

int maxArr(int arr[], int n){
    if(n == 1){
        return arr[0];
    }
    if(n == 2){
        return max(arr[0], arr[1]);
    }
    int ans1 = maxArr(arr, n-1);
    int ans2 = arr[n-1];
    return max(ans1, ans2);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = maxArr(arr, n);
    cout << p << endl;
}
