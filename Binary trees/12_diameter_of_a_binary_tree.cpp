#include <iostream>
#include <vector>

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
  if(node == NULL){
      return -1;
  }
  return max(height(node->left), height(node->right)) + 1;
}


int diameter(Node* root)
{
    Node* node = root;
    if(node == NULL){
        return 0;
    }
    
    // maximum distance of two nodes in lhs
    int lhs = diameter(node->left);
    // maximum distance of two nodes in rhs
    int rhs = diameter(node->right);
    // maximum distance between left deepest and right deepest node 
    int d = height(node->left) + height(node->right) + 2;
    return max(lhs, max(rhs, d));
}

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
  int dia = 0;
  dia = diameter(root);
  cout << dia;
}