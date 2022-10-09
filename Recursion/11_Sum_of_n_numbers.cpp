#include<iostream>
using namespace std;

int sum(int n){
    if(n == 1){
        return 1;
    }
    int ans1 = sum(n-1);
    return ans1 + n;
}

int main(){
    int n;
    cin >> n;
    cout << sum(n);
}