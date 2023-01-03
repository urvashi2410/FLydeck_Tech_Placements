#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>>ppi;

vector<int>mergeKSortedLists(vector<vector<int>>& lists) {
    vector<int> ans;
    priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
    
    // pushing first element of all the lists in the priority queue 
    for(int i = 0; i < lists.size(); i++){
        pq.push({lists[i][0], {i, 0}});
    }
    
    while(!pq.empty()){
        ppi curr = pq.top();
        pq.pop();
        
        int arrNo = curr.second.first;
        int idx = curr.second.second;
        
        ans.push_back(curr.first);
        
        // if list is having more elements then push other element from that list into pq
        if(idx + 1 < lists[arrNo].size()){
            pq.push({lists[arrNo][idx + 1], {arrNo, idx + 1}});
        }
    }
    
    return ans;
}

int main() {
  int k;
  cin >> k;
  vector<vector<int>>lists;
  for (int i = 0; i < k; i++) {
    vector<int>list;

    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;
      list.push_back(data);
    }

    lists.push_back(list);
  }

  vector<int> mlist = mergeKSortedLists(lists);
  for (int val : mlist) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}