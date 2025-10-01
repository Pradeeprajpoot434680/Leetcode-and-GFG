#include<bits/stdc++.h>
using namespace std;

int smallestNumber(int n) {
    int i =0;
    int ans=0;
    for(int i=0; i<15; i++){
        if(n>= pow(2,i) && n< pow(2,i+1)){
            ans = i;
            break;
        }
    }

    return pow(2,ans+1)-1;
}

int main(){
    cout<<smallestNumber(6);
    return 0;
}