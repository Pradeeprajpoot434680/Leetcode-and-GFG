#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int diff = start ^ goal;
    int ans=0;
    while(diff){
        ans+= (diff&1);
        diff>>=1;
    }

    return ans;
}

int main(){
     cout<<minBitFlips(3,4);
    // cout<<(3^4);
    return 0;
}