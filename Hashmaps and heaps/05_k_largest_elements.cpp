#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findKthLargest(vector<int> const& arr, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i < arr.size(); i++){
        if(i < k){
            pq.push(arr[i]);
        }
        else{
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  int k;
  cin >> k;
  findKthLargest(arr, k);

  return 0;

}