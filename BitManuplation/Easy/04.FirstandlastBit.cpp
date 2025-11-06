#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:

    int onlyFirstAndLastAreSet(long long int n) {
        // complete the function here
        if((n & 1) == 0)return 0;
        
        bool isOneFound=0;
        
        for(int i=1; i<32; i++){
            if(((n>>i)&1) && !isOneFound){
                isOneFound=1;
                continue;
            }
            
            if(((n>>i)&1) && isOneFound){
                return 0;
            }
        }
        
        
        return 1;
    }
};