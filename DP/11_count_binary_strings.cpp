#include <bits/stdc++.h>
using namespace std;

int countStrings(int n){
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
        int temp = a + b;
        b = a;
        a = temp;
    }
    return a + b;
}

int main(){
    int n;
    cin >> n;

    cout << countStrings(n) << endl;
}