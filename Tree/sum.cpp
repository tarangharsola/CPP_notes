#include <iostream>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int traversal(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int sum = traversal(root->left);
    sum = sum + root->data;
    sum = sum + traversal(root->right);

    return sum;

int main() {
    TreeNode *a = new TreeNode(40);
    TreeNode *b = new TreeNode(20);
    TreeNode *c = new TreeNode(60);
    TreeNode *d = new TreeNode(30);
    TreeNode *e = new TreeNode(10);
    TreeNode *f = new TreeNode(25);
    TreeNode *g = new TreeNode(55);
    TreeNode *h = new TreeNode(100);
    TreeNode *i = new TreeNode(67);
    TreeNode *j = new TreeNode(50);
    
    a->left = b;
    a->right = c;
    
    b->left = d;
    b->right = e;
    
    c->left = f;
    c->right = g;
    
    e->left = h;
    e->right = i;
    
    g->left = j;

    int sum = traversal(a);
    cout << sum << endl;
}