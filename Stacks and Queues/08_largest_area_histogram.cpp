#include<bits/stdc++.h>
using namespace std;

vector<int>NSR(vector<int>arr, int n){
    stack<int> s;
    vector<int> ans(n);
    
    ans[n-1] = n;
    s.push(n-1);
    
    for(int i = n-2; i >= 0; i--){
        if(s.size() > 0 && arr[s.top()] < arr[i]){
            ans[i] = s.top();
        }
        else{
            if(s.size() > 0 && arr[s.top()] >= arr[i]){
                while(!s.empty() && arr[s.top()] >= arr[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    ans[i] = n;
                }
                else{
                    ans[i] = s.top();
                }
            }
        }
        s.push(i);
    }
    return ans;
}

vector<int>NSL(vector<int>arr, int n){
    stack<int> s;
    vector<int> ans(n);
    
    ans[0] = -1;
    s.push(0);
    
    for(int i = 1; i < n; i++){
        if(s.size() > 0 && arr[s.top()] < arr[i]){
            ans[i] = s.top();
        }
        else{
            if(s.size() > 0 && arr[s.top()] >= arr[i]){
                while(!s.empty() && arr[s.top()] >= arr[i]){
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
    
    vector<int>rb = NSR(arr, n);
    vector<int>lb = NSL(arr, n);
    
    int maxArea = INT_MIN;
    for(int i = 0; i < n; i++){
        int width = rb[i] - lb[i] - 1;
        int area = arr[i] * width;
        maxArea = max(area, maxArea);
    }
    
    cout << maxArea << endl;
}