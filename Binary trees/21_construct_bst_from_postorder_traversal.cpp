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
TreeNode *bstFromPostorder(vector<int> &postorder, int lr, int rr){
    if(idx == -1 || postorder[idx] < lr || postorder[idx] > rr){
        return NULL;
    }
    
    TreeNode* node = new TreeNode(postorder[idx--]);
    node->right = bstFromPostorder(postorder, node->val, rr);
    node->left = bstFromPostorder(postorder, lr, node->val);
    return node;
}

TreeNode *bstFromPostorder(vector<int> &postorder){
    int n = postorder.size();
    idx = n - 1;
    int lr = -1e8;
    int rr = 1e8;
    return bstFromPostorder(postorder, lr, rr);
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

    TreeNode *root = bstFromPostorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}