#include<bits/stdc++.h>
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
    vector<int> bottomView(Node *root) {
        // code here
        queue<pair<int, Node*>> q;
        map<int, int> mp;
        q.push(make_pair(0, root));
        while(!q.empty()){
            auto front= q.front();
            q.pop();
            Node* node= front.second;
            int value=node->data;
            int col= front.first;
            mp[col]= value;
            if(node->left){
                q.push(make_pair(col-1, node->left));
            }
            if(node->right){
                q.push(make_pair(col+1, node->right));
            }
        }
        vector<int> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;;
    }
};

int main(){
    
}