#include<bits/stdc++.h>
using namespace std;


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
    int maxXor(int num){
        TrieNode * node = root;
        int ans=0;
        for(int i=31; i>=0; i--){
            int b = (num>>i)&1;
            bool opposite = b ^ 1;
            if(node->bit[opposite] != NULL){
                ans |= (1<<i);
                node = node->bit[opposite];
            }
            else {
                node = node->bit[b];
            }
        }

        return ans;
    }

};
class Solution {
public:
    Trie t;
    int findMaximumXOR(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            t.insert(nums[i]);
        }

        int ans =0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans,t.maxXor(nums[i]));
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums={2,5,7};
    cout<<"Max ans is:"<<s.findMaximumXOR(nums);
    return 0;
}