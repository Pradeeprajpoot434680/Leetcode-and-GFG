#include<bits/stdc++.h>
using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    int flips = 0;
    int n = nums.size();
    int currentFlips=0;
    vector<int>fliped(n,0);
    for(int i=0; i<n; i++){
        if(i>=k && fliped[i-k]==true){
            currentFlips--;
        }

        if(nums[i] == currentFlips%2){//if currentFlips is even and nums[i] = 0 then flip and currentFlips == odd and nums[i]==1 then flip
            if(i+k>n)return -1;
            flips++;
            fliped[i]=1;
            currentFlips++;
        }
    }
    return flips;
}

int main(){
    int k = 3;
    vector<int>arr={1,1,0,0,1,0,1,1,0,0,0,1,0,1};
    cout<<minKBitFlips(arr,k);
}

// space optimization use the input arr and change the  arr[i]=5;