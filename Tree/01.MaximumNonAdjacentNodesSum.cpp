#include <bits/stdc++.h>
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


class Solution {
  public:
  unordered_map<Node*,int>m;
  
    int solve(Node * root){
        
        if(!root)return 0;
        //pick not 
        if(m.find(root) != m.end())return m[root];
        int pick = root->data + (root->left ? solve(root->left->left) + solve(root->left->right): 0) + ( root->right ? solve(root->right->left) + solve(root->right->right) : 0);
        int not_pick = 0 + solve(root->left) + solve(root->right);
        
        return m[root] = max(pick,not_pick);
    }
    int getMaxSum(Node *root) {
        // code here
        return solve(root);
    }
};

int main(){
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    int result = sol.getMaxSum(root);
    cout << result << endl;
}