#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        // code here
        int ans=-1;
        bool oneFound = 0;
        for(int i=0; i<32; i++){
            if(((n>> i) & 1)){
                
                if(!oneFound){
                    ans=i+1;
                }else{
                    return -1;
                }
                oneFound=1;
            }
        }
        return ans;
    }
};

int main(){
    
}