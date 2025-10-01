#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums) {
    int flips=0;
    int n = nums.size();
    int totalFlips=0;
    for(int i=0; i<n; i++){
        if(nums[i] == totalFlips % 2)
        {
            flips++;
            totalFlips++;
        }
    }

    return flips;
}
int main(){
    vector<int>arr={0,0,0,1,1,0,1,0};
    cout<<minOperations(arr);
}