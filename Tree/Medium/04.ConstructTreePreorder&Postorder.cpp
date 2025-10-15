#include<bits/stdc++.h>

using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    unordered_map<int,int> postIndex;

    Node* solve(int preStart, int preEnd, int postStart, int postEnd, vector<int> &pre, vector<int> &post) {
        if (preStart > preEnd || postStart > postEnd) return NULL;

        Node* root = new Node(pre[preStart]);

        // Leaf node condition
        if (preStart == preEnd) return root;

        // Next element in preorder is left child → find in postorder
        int leftChild = pre[preStart + 1];
        int leftChildIndex = postIndex[leftChild];

        int leftSubtreeSize = leftChildIndex - postStart + 1;

        // Build left and right subtrees
        root->left = solve(preStart + 1, preStart + leftSubtreeSize, postStart, leftChildIndex, pre, post);
        root->right = solve(preStart + leftSubtreeSize + 1, preEnd, leftChildIndex + 1, postEnd - 1, pre, post);

        return root;
    }

    Node* constructTree(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        for (int i = 0; i < n; i++) {
            postIndex[post[i]] = i; // store index of each element in postorder
        }
        return solve(0, n - 1, 0, n - 1, pre, post);
    }
};

/*
Node* constructTree(vector<int>& pre, vector<int>& post, int& preIndex, int l, int r, int size) {
    // Base case
    if (preIndex >= size || l > r) return NULL;

    // Create current root node
    Node* root = new Node(pre[preIndex++]);

    // If this node is a leaf node
    if (l == r || preIndex >= size) return root;

    // Next element in preorder is left child → find it in post[]
    int i;
    for (i = l; i <= r; i++) {
        if (post[i] == pre[preIndex])
            break;
    }

    // Construct left and right subtrees
    if (i <= r) {
        root->left = constructTree(pre, post, preIndex, l, i, size);
        root->right = constructTree(pre, post, preIndex, i + 1, r - 1, size);
    }

    return root;
}

// Build tree wrapper
Node* constructTree(vector<int>& pre, vector<int>& post) {
    int preIndex = 0;
    int size = pre.size();
    return constructTree(pre, post, preIndex, 0, size - 1, size);
}*/

int main(){
    Solution s;
    
}