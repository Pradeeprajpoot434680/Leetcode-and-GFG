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
     vector<int> zigzagLevelOrder(Node* root) {
        // vector<vector<int>>ans;
        vector<int>ans;
        if(!root)return ans;
        queue<Node *>q;
        q.push(root);
        bool flag = true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>row(n);
            for(int i=0; i<n; i++)
            {
                int index = flag ? i:n-i-1;
                Node * node = q.front();
                q.pop();
                row[index] = node->data;

                if(node->left)
                {
                    q.push(node->left);

                }

                if(node->right)
                {
                    q.push(node->right);

                }
            }

            for(int i=0; i<row.size(); i++){
                ans.push_back(row[i]);
            }
            flag = !flag;
        }
        return ans;
    }
    vector<int> zigZagTraversal(Node* root) {
        // code here
        return   zigzagLevelOrder(root);
    }
};

int main(){
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> result = sol.zigZagTraversal(root);
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;   
}