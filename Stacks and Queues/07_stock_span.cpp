#include<bits/stdc++.h>
using namespace std;

vector<int>stockSpan(vector<int>arr, int n){
    stack<int>s;
    vector<int>ans(n);
    
    ans[0] = 1;
    s.push(0);
    for(int i = 1; i < n; i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            s.pop();
        }
        
        if(s.empty()){
            ans[i] = i + 1;
        }
        else{
            ans[i] = i - s.top();
        }
        s.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int>ans(n);
    ans = stockSpan(arr, n);
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
} 