#include<bits/stdc++.h>
using namespace std;

int minKBitFlips(vector<int>& nums, int k) {
    int flips = 0;
    int n = nums.size();
    int currentFlips=0;
    deque<int>dq;
    for(int i=0; i<n; i++){
        if(i>=k){
            currentFlips-=dq.front();
            dq.pop_front();
        }

        if(nums[i] == currentFlips%2){//if currentFlips is even and nums[i] = 0 then flip and currentFlips == odd and nums[i]==1 then flip
            if(i+k>n)return -1;
            flips++;
            dq.push_back(1);
            currentFlips++;
        }
        else{
            dq.push_back(0);
        }
        
    }
    return flips;
}
int main(){
    vector<int>arr={0,0,1,1,1,0,1,1};
    int k = 3;
    cout<<minKBitFlips(arr,k);
}