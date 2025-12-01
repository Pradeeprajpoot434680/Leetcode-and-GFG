#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class TrieNode {
    public:
    TrieNode * bit[2];
    TrieNode(){
        bit[0]=NULL;
        bit[1] = NULL;
    }
};
class Trie {
    private:
    TrieNode * root;
    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
          TrieNode * node = root;
          for(int i=31; i>=0; i--){
            bool b = (num>>i)&1;
            if(node->bit[b] == NULL){
                node->bit[b] = new TrieNode();
            }
            node = node->bit[b];
          }
    }
    
    
    int minXor(int num){
        TrieNode * node = root;
        int ans=0;
        for(int i=31; i>=0; i--){
            int b = (num>>i)&1;
            //bool opposite = b ^ 1;
            if(node->bit[b] != NULL){
               node = node->bit[b];
               
            }
            else {
                ans |= (1<<i);
                node = node->bit[b^1];
             }
        }

        return ans;
    }

};
class Solution {
  public:
    int minxorpair(int N, int arr[]) {
        // code here
        Trie t;
        int ans = INT_MAX;
        t.insert(arr[0]);
        for(int i=1; i<N; i++){
            ans = min(ans,t.minXor(arr[i]));
            t.insert(arr[i]);
        }
        
       
        return ans;
        
        
        
    }
};

int main(){
    Solution s;
    int arr[5] = {4,5,2,6,7};
    cout<<"Ans is:"<<s.minxorpair(5,arr);
}