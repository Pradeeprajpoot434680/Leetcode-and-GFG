#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        for(int i=0; i<32; i++){
            if(((n>>i)&1) == 0){
               n = n | (1 << i);
                return n;
            }
        }
        return n;
    }
};