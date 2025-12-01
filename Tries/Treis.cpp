#include<bits/stdc++.h>
using namespace std;
class TrieNode {
    public:
    TrieNode* childern[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;

        for(int i=0; i<26; i++){
            childern[i] = NULL;
        }
    }
};

class Trie {
    private:
    TrieNode * root;
    public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s){
        TrieNode * node = root;

        for(char c:s){
            int idx = c -'a';
            if(node->childern[idx] == NULL){
                node->childern[idx] = new TrieNode();
            }
            node  = node->childern[idx];
        }
        node->isEnd = true;
    }

    bool search(string s){
        TrieNode * node = root;

        for(char ch:s){
            int idx = ch - 'a';
            if(node->childern[idx] == NULL){
                return false;
            }
            node=node->childern[idx];
        }
        return node->isEnd;
    }

    bool searchPrefix(string prefix){
         TrieNode * node = root;

        for(char ch:prefix){
            int idx = ch - 'a';
            if(node->childern[idx] == NULL){
                return false;
            }
            node=node->childern[idx];
        }
        return true;

    }

};


int main() {
    Trie t;

    t.insert("apple");
    t.insert("app");
    t.insert("apt");

    cout << t.search("app") << endl;        // 1 (true)
    cout << t.search("apply") << endl;      // 0 (false)
    cout << t.searchPrefix("ap") << endl;     // 1 (true)
    cout << t.searchPrefix("ca") << endl;     // 0 (false)
}

