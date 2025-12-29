#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        if(k==1)return 1;
        string temp="1";
        while(1){
            if(temp.size()<=10){
                int num = stoi(temp);
                if(num >=k && num % k == 0){
                    return temp.size();
                }
               
                temp.push_back('1');
                   
                
            } else {
                break;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int>values = {5,2,6,234,785,23436,24,6575,2,54645,1,2,345};
    for(int i=0; i<values.size(); i++){
        cout <<"Solution for :"<<values[i] << " => IS => "<< sol.minAllOneMultiple(values[i]) << endl;

    }
    return 0;
}