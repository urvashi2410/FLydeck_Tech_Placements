#include <bits/stdc++.h> 
bool faultyKeyboard(string expected, string typed) {
    // Write your code here.
    int n = expected.size();
    int k = typed.size();
    
    int i = 0;
    int j = 0;
    
    if(k < n){
        return false;
    }
    while(i < n && j < k){
        if(expected[i] == typed[j]){
            i++;
            j++;
        }
        else{
            if(i > 0 && expected[i-1] == typed[j]){
                j++;
            }
            else{
                return false;
            }
        }
    }
    
    while(j < k){
        if(expected[i-1] != typed[j]){
            return false;
        }
        j++;
    }
    if(i < n){
        return false;
    }
    return true;
}