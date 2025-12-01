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

bool dfs(int index,string &word,TrieNode * node){
    if(!node)return false;

    if(index == word.size()){
        return node->isEnd;
    }


    char ch = word[index];


    if(ch != '.'){
        int idx = ch - 'a';

        return dfs(index+1,word,node->childern[idx]);
    }


    for(int i=0; i<26; i++){
        if(node->childern[i] != NULL){
            if(dfs(index+1,word,node->childern[i])){
                return true;
            }
        }
    }

    return false;
}

class WordDictionary {
    private:
    TrieNode * root;
    

    public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string s) {
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
    
    bool search(string s) {
        return dfs(0, s, root);
    }
};
