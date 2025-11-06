#include<bits/stdc++.h>
using namespace std;;
// User function Template for C++
class Solution {
  public:
    long long int setAllOddBits(long long int n) {
        // code here
        int MSB = 0;
        for(int i=0; i<32; i++){
            if(((n>>i)&1)){
                MSB=i;
            }
        }
        for(int i=0; i<MSB; i+=2){
            n = ((1<<i) | n);
        }
        
        return n;
    }
};