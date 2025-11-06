#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> printNumHavingAltBitPatrn(int n) {
        // Code here
        vector<int>ans;
        int x=0;
        for(int i=0; i<32; i++){
            if(i%2==0){
                x = (1|(x<<1)) ;
            }
            else{
                x = (x<<1);
            }
            
            
            
            if(x<=n && x>=1){
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};
