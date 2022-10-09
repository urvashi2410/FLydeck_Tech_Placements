#include <iostream>
using namespace std;

bool powerOf2(int n){
    // 2^0 = 1
    if(n == 1){
        return true;
    }
    
    // if number is odd then cannot be a power of 2
    if(n % 2 != 0 || n == 0){
        return false;
    }
    return powerOf2(n/2);
}

int main(){
    int n;
    cin >> n;
    if(powerOf2(n) == 1){
        cout << "True";
    }
    else{
        cout << "False";
    }
}