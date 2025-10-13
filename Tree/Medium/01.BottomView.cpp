#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;

    Node(int x){
        data = x;
        left=NULL;
        right = NULL;
    }
};

vector<int> BottomView(Node * root){
    queue<pair<int,Node *>>q;
    map<int,int>m;

    q.push({0,root});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int col = front.first;
        Node * node = front.second;
        int val = node->data;

        m[col] = val;

        if(node->left){
            q.push({col-1,node->left});
        }
        if(node->right){
            q.push({col+1,node->right});
        }
    }

    vector<int>ans;

    for(auto it:m){
        ans.push_back(it.second);
    }

    return ans;


}

int main(){
    
}