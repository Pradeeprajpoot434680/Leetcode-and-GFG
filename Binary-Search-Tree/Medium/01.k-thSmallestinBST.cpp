#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
        int ans=-1;
        int p;
    void solve(Node * root){
        if(!root)return;
        
        solve(root->left);
        p--; 
        if(p==0){
            ans = root->data;
            return;
        }
        solve(root->right);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        p=k;
        solve(root);
        
        return ans;
    }
    
};

int main(){
    Solution sol;
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->left->right = new Node(2);
    int k = 1;
    int result = sol.kthSmallest(root,k);
    cout << result << endl;
}