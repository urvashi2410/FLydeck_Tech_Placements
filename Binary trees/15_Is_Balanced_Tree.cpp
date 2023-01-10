#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
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
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

//Display function
void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}


//Height function
int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

/*
MEthod = 2
class BalPair{
public:
    int ht;
    bool isBal;
};

BalPair isBal(Node* node){
    if(node == NULL){
        BalPair bp;
        bp.ht = 0;
        bp.isBal = true;
        return bp;
    }
    
    BalPair lp = isBal(node->left);
    BalPair rp = isBal(node->right);
    
    BalPair mp;
    mp.isBal = (abs(lp.ht - rp.ht) <= 1) && lp.isBal && rp.isBal;
    mp.ht = max(lp.ht, rp.ht) + 1;
    return mp;
}
*/

/*
// MEthod = 1
bool isbal = true;
int isbalance(Node* node)
{
    if(node == NULL){
        return 0;
    }
    
    int l = isbalance(node->left);
    int r = isbalance(node->right);
    int gap = abs(l - r);
    if(gap > 1){
        isbal = false;
    }
    int th = max(l, r) + 1;
    return th;
}
*/

int main() {
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (tmp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(tmp);
    }
  }
  Node* root = constructTree(arr);

  BalPair r = isBal(root);
  if (r.isBal == 1)
    cout << "true";
  else
    cout << "false";
}