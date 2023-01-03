#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    
    unordered_map<char, int>m;
    
    for(int i = 0; i < str.size(); i++){
        if(m.find(str[i]) == m.end()){
            m[str[i]] = 1;
        }
        else{
            m[str[i]]++;
        }
    }
    
    char ansCh = str[0];
    int ans = 0;
    for(auto a : m){
        if(a.second > ans){
            ans = a.second;
            ansCh = a.first;
        }
    }
    cout << ansCh;
}
