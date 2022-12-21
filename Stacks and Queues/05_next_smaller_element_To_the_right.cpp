#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>NGL(vector<int>arr, int n){
    stack<int> s;
    vector<int> ans(n);
    
    ans[n-1] = -1;
    s.push(arr[n-1]);
    
    for(int i = n-2; i >= 0; i--){
        if(s.size() > 0 && s.top() < arr[i]){
            ans[i] = s.top();
        }
        else{
            if(s.size() > 0 && s.top() > arr[i]){
                while(!s.empty() && s.top() > arr[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = s.top();
                }
            }
        }
        s.push(arr[i]);
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