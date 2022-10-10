#include<iostream>
using namespace std;

void pascalTriangle(int arr[], int n){
    if(n < 1){
        return;
    }

    int temp[n-1];
    for(int i = 0; i < n-1; i++){
        temp[i] = arr[i] + arr[i+1];
    }

    pascalTriangle(temp, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pascalTriangle(arr, n);
    return 0;
}