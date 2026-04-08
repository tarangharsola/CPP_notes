#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int x = 1 + height(root->left);
    int y = 1 + height(root->right);

    return max(x, y);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    int h = height(root);
    cout << h << endl;
    
    return 0;
}