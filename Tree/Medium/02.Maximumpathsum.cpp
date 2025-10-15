#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int maxAns = INT_MIN;
    int maxSumPath(Node * root){
        // if(!root->left && ! root->right)return root->data;
        if(!root)return 0;
        int leftPart =-10e5;
        int rightPart =-10e5;
        
            leftPart = max(0,maxSumPath(root->left));
        
        
       
            rightPart =  max(0,maxSumPath(root->right));
        
        int x= root->data + leftPart+rightPart;
        maxAns = max(maxAns,x);
        return root->data + max(leftPart,rightPart);
    }
    int findMaxSum(Node *root) {
        // code here
         maxSumPath(root);
         return maxAns;
    }
};

int main(){
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    int result = sol.findMaxSum(root);
    cout << result << endl;
}