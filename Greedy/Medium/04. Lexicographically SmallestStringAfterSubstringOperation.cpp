#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestString(string s) {
        string temp = s;
        int i=0;
        int n=s.size();
        bool flag = 0;
        while(i < n && s[i]=='a'){
            i++;
        }
        while(i < n && temp[i] != 'a'){
            temp[i] = temp[i]-1;
            flag = 1;
            i++;
        }
        if(!flag){
            temp[n-1] = 'z';
        }
        return temp;
    }
};

int main(){
    Solution s;
    string str= "cbabc";
    cout<< s.smallestString(str);
}