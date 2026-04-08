/*
Same as Problem 5 but instead of returning true/false, 
return all root-to-leaf paths whose node values sum to targetSum.
Example:
        5
       / \
      4   8
     /   / \
    11  13   4
   /  \       \
  7    2       1

targetSum = 22
Expected Output:
[5, 4, 11, 2]
[5, 8, 4, 5]  (if applicable)

Hint
DFS + backtracking. Maintain a current path list.
At a leaf, if remaining == 0, add a COPY of the path to result 
(not the list itself — the list keeps changing). 
After both recursive calls return, remove the last element. 
This removal is the backtrack.


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
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);
    
    vector <int> path;
    vector <vector <int>> result;

    int target = 22;
    bool b = false;
    
    dfs(root, path, result);
    vector <vector <int>> vec;
    
    for(vector <int> v:result) {
        int sum = 0;
        for(int i:v) {
            sum = sum + i;
        }
        if(sum == target) {
            b = true;
            vec.push_back(v);
        } 
    }

    if(b) {
        for(vector <int> v:vec) {
            for(int i:v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}