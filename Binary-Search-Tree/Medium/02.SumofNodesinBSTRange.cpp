#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    int ans=0;
    void solve(Node * root,int l,int r){
        if(!root)return ;
        
        if(root->data >= l && root->data <= r){
            ans += root->data;
        }
        if(root->data >= l)
        solve(root->left,l,r);
        if(root->data<=r)
        solve(root->right,l,r);
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        solve(root,l,r);
        return ans;
    }
};


int main(){
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);
    int l = 7;
    int r = 15;
    int result = sol.nodeSum(root,l,r);
    cout << result << endl;
}