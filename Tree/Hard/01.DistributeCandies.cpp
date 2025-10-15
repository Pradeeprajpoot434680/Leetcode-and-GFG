#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};


class Solution {
  public:
    int moves =0;
    int solve(Node * root){
        if(!root)return 0;
        
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        moves += abs(l) + abs(r);
        
        return (l+r+root->data)-1;
        
    }
    int distCandy(Node* root) {
        // code here
        solve(root);;
        return moves;
    }
};

int main(){
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(0);
    root->right = new Node(0);
    root->left->left = new Node(3);
    root->left->right = new Node(0);
    root->right->right = new Node(0);
    int result = sol.distCandy(root);
    cout << result << endl;
}