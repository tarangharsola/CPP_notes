/*
Given the root of a binary tree, find and print the longest path from root to any leaf. If multiple paths tie, print any one.
Example:
      1
     / \
    2   3
   / \
  4   5
Expected Output:
Longest path length: 3

Hint
Collect all path lengths in a vector (like Problem 2). After DFS completes, find the maximum using max_element. Alternatively, track a global max variable and update it at each leaf.





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

    int length = 0;
    vector <int> longest_path;
    
    for(vector <int> v:result) {
        if(length<v.size()) {
            length = v.size();
            longest_path = v;
        }
    }

    for(int i:longest_path) {
        cout << i << "-->";
    }
    
    return 0;
}