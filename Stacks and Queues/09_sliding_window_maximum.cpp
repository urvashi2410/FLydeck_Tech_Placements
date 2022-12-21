#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    stack<int>s;
    vector<int>ans(n);
    s.push(n-1);
    ans[n-1] = n;
    
    for(int i = n-2; i >= 0; i--){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        
        if(s.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = s.top();
        }
        s.push(i);
    }
    
    int j = 0;
    for(int i = 0; i <= n-k; i++){
        if(j < i){
            j = i;
        }
        
        while(ans[j] < i + k){
            j = ans[j];
        }
        cout << arr[j] << endl;
    }
    
}