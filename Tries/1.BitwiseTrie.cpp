#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    TrieNode * bit[2];
    TrieNode(){
        bit[0] = NULL;
        bit[1] = NULL;
    }
};

class BitwiseTrie {
    TrieNode * root;
    public:
    BitwiseTrie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode * node = root;
        for(int i=31; i>=0; i--){
            int b = (num>>i)&1;
            if(node->bit[b]  == NULL){
                node->bit[b] = new TrieNode();
            }

            node = node->bit[b];
        }

    }

};

int main() {
    BitwiseTrie t;
    t.insert(5);
    t.insert(7);
}
