#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums) {
    int flips=0;
    int n = nums.size();
    vector<bool>fliped(n,0);
    int prevFliped=0;
    for(int i=0; i<n; i++){
        if(i>=3 && fliped[i-3]==1)prevFliped--;

        if(nums[i] == prevFliped % 2){
            if(i+3>n)return -1;
            prevFliped++;
            flips++;
            fliped[i]=1;
        }
    }

    return flips;
}
int main(){
    vector<int>arr={0,0,0,1,1,0,1,0};
    cout<<minOperations(arr);
}