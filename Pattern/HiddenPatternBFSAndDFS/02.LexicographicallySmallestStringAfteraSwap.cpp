#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getSmallestString(string s) {
        int n= s.size();
        // bool flag = 0;
        for(int i=0; i<n-1; i++){
            if(s[i] > s[i+1] && (s[i] % 2 == s[i+1] % 2)){
                swap(s[i],s[i+1]);
                // flag =1;
                break;
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    string str= "4321";
    cout<< s.getSmallestString(str);
}