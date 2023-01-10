#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node
{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data, Node* left, Node* right)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++], nullptr, nullptr);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

    vector<Node*>path;
    bool find(Node* node, int data) {
        if(node == NULL){
            return false;
        }
        
        if(node->data == data){
            path.push_back(node);
            return true;
        }
        
        bool filc = find(node->left, data);
        if(filc){
            path.push_back(node);
            return true;
        }
        
        bool firc = find(node->right, data);
        if(firc){
            path.push_back(node);
            return true;
        }
        return false;
    }

    vector<Node*> nodeToRootPath(Node* node, int data) {
        if(find(node, data)){
            return path;
        }
    }
    
    void kLevelsDown(Node* node, int k, Node* blocker) {
        if(node == NULL || k < 0 || node == blocker){
            return;
        }
        if(k == 0){
            cout << node->data << endl;
        }
        kLevelsDown(node->left, k-1, blocker);
        kLevelsDown(node->right, k-1, blocker);
    }
    
    void printKNodesFar(Node* node, int data, int k) {
        vector<Node*>path = nodeToRootPath(node, data);
        for(int i = 0; i < path.size(); i++){
            kLevelsDown(path[i], k-i, i == 0? NULL: path[i-1]);
        }
    }
int main()
{
  vector<int> arr;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string inp;
    cin >> inp;
    if (inp != "n") {
      arr.push_back(stoi(inp));
    }
    else {
      arr.push_back(-1);
    }
  }

  int data;
  cin >> data;
  int k;
  cin >> k;
  Node* root = constructTree(arr);
  printKNodesFar(root, data, k);

  return 0;
}