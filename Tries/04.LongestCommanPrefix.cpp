#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int childCount;
    TrieNode() {
        isEnd = false; 
        childCount=0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* node = root;
       
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
                node->childCount++;
                
            }
           
            node = node->children[idx];
        }
        node->isEnd = true; 
    }

    string getLCP(){
        string lcp = "";
        TrieNode * node = root;
        while(node != NULL && node->childCount == 1 && node->isEnd == false){

            for(int i=0; i<26; i++){
                if(node->children[i] != NULL){
                    lcp.push_back(char(i+'a'));
                     node = node->children[i];
                    break;
                }
            }
        }
          return lcp;
    }
};
        

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;

        for (string s : strs)
            t.insert(s);

        return t.getLCP();
    }
};


int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
