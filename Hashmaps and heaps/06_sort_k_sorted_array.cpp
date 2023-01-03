#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i <= k; i++){
        pq.push(arr[i]);
    }
    
    for(int i = k + 1; i < n; i++){
        cout << pq.top() << endl;
        pq.pop();
        pq.push(arr[i]);
    }
    
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    int data;
    cin >> data;
    arr[i] = data;
  }
  int k;
  cin >> k;
  sortK(arr, n, k);
  return 0;
}