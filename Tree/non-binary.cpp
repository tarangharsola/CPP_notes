#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    char data;
    vector <TreeNode*> node;
    TreeNode(char val) {
        data = val;
    }

    void add(TreeNode *n) {
        node.push_back(n);
    }
};

void traversal(TreeNode* root) {
    
    cout << root->data << endl;

    if(root->node.empty()) {
        return;
    }

    for(TreeNode* n:root->node) {
        traversal(n);
    }
}

int main() {
    TreeNode* root = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    TreeNode* d = new TreeNode('D');
    TreeNode* e = new TreeNode('E');
    TreeNode* f = new TreeNode('F');
    TreeNode* g = new TreeNode('G');
    TreeNode* h = new TreeNode('H');
    TreeNode* i = new TreeNode('I');
    TreeNode* j = new TreeNode('J');
    TreeNode* k = new TreeNode('K');

    root->add(b);
    root->add(c);

    b->add(d);
    b->add(e);
    b->add(f);

    e->add(i);
    e->add(j);

    c->add(g);
    c->add(h);

    g->add(k);

    traversal(root);
}