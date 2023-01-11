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

int idx = 0;
TreeNode *bstFromPreorder(vector<int> &preorder, int lr, int rr){
    if(idx == preorder.size() || preorder[idx] < lr || preorder[idx] > rr){
        return NULL;
    }
    
    TreeNode* node = new TreeNode(preorder[idx++]);
    node->left = bstFromPreorder(preorder, lr, node->val);
    node->right = bstFromPreorder(preorder, node->val, rr);
    return node;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int lr = -1e8;
    int rr = 1e8;
    return bstFromPreorder(preorder, lr, rr);
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
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}