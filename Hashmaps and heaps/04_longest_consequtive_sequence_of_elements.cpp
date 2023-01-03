#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    unordered_map<int, int>m;
    for(int i : arr){
        m[i] = true;
    }
    
    for(int i : arr){
        if(m.find(i-1) != m.end()){
            m[i] = false;
        }
    }
    
    int maxLen = 0;
    int mval = 0;
    for(int i : arr){
        if(m.find(i) != m.end() && m[i] == true){
            int len = 1;
            int val = i;
            
            while(m.find(i + len) != m.end()){
                len++;
            }
            
            if(maxLen < len){
                maxLen = len;
                mval = val;
            }
        }
    }
    
    for(int i = 0; i < maxLen; i++){
        cout << mval + i << endl;
    }
    
    return 0;
}