#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isBitSet(int N) {
        // Check if N & (N + 1) equals 0
        if(N==0)return 0;
        return (N & (N + 1)) == 0;
    }
};


int main(){
    Solution s;
    s.isBitSet(43);
}