#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>NGL(vector<int>arr, int n){
    stack<int> s;
    vector<int> ans(n);
    
    s.push(n-1);
    for(int i = n-2; i >= 0; i--){
        if(!s.empty() && arr[s.top()] < arr[i]){
            while(!s.empty() && arr[s.top()] < arr[i]){
                int pos = s.top();
                ans[pos] = arr[i];
                s.pop();
            }
        }
        s.push(i);
    }
    
    while(!s.empty()){
        int pos = s.top();
        ans[pos] = -1;
        s.pop();
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
    ans = NGL(arr, n);
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}