#include<iostream>
#include<string>
using namespace std;
#include<unordered_map>
#include<vector>
#include<algorithm>

bool divideArray(vector<int>& nums) {
    unordered_map<int,int>m;
    for(int i:nums){
        m[i]++;
    }

    for(auto it:m){
        if(it.second % 2 != 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    vector<int>nums={3,2,3,2,2,2};
    cout<<divideArray(nums);
    return 0;
}