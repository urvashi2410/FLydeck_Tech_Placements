#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *constructFromInOrder(vector<int> &in, int si, int ei){
    if(si > ei){
        return NULL;
    }
    
    int mid = (si + ei) / 2;
    TreeNode* node = new TreeNode(in[mid]);
    
    node->left = constructFromInOrder(in, si, mid-1);
    node->right = constructFromInOrder(in, mid + 1, ei);
    return node;
}

TreeNode *constructFromInOrder(vector<int> &in){
    int n = in.size();
    return constructFromInOrder(in, 0, n-1);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}

int main()
{
    solve();
    return 0;
}