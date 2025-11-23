#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(string S) {
        const long long MOD = 1000000007;

        long long countA = 0, countAB = 0, countABC = 0;

        for(char ch : S)
        {
            if(ch == 'a')
            {
                countA = (2 * countA + 1) % MOD;
            }
            else if(ch == 'b')
            {
                countAB = (2 * countAB + countA) % MOD;
            }
            else if(ch == 'c')
            {
                countABC = (2 * countABC + countAB) % MOD;
            }
        }

        return countABC;
    }
};

int main(){

}