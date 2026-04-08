/*Given the root of a binary tree, print all paths from root to every leaf node.
Example:
      1
     / \
    2   3
   / \
  4   5
Expected Output:
1 -> 2 -> 4
1 -> 2 -> 5
1 -> 3

Hint
Use DFS. Carry a path list as you go deeper. When you reach a leaf (no left, no right child), print the path. Remove the last element when you return from a node — that is the backtrack step.
*/

#include <iostream>
#include <vector>

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

void dfs(Node* root, vector<int> &path, vector<vector<int>> &result) {
    if(root == nullptr) return;
    
    path.push_back(root->data);
    if(root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
    }
    
    dfs(root->left, path, result);
    dfs(root->right, path, result);
    
    path.pop_back();
    return;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector <int> path;
    vector <vector <int>> result;
    
    dfs(root, path, result);
    
    for(vector <int> v:result) {
        for(int i:v) {
            cout << i << "-->";
        }
        cout << endl;
    }
    
    return 0;
}