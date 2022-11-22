#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    int a = fibonacci(n-1);
    int b = fibonacci(n-2);
    return a + b;
}

int main(){
    int n;
    cin >> n;
    cout << fibonacci(n);
}