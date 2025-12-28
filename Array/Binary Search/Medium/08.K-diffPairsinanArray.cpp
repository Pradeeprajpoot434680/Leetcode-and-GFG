#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -1 for not present otherwise return index to help out of bound
    int isPresent(int start,int end,vector<int>&nums,int k){
        if(k > nums[nums.size()-1])return nums.size();

        while(start <= end){
            int mid = start + (end - start);

            if(nums[mid] ==k){
                return mid;
            }
            else if(nums[mid] < k){
                start  = mid + 1;
            }
            else 
                end = mid - 1;
        }

        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
       int n =nums.size();
       sort(nums.begin(),nums.end());

       int count=0;

       for(int i=0; i<n; i++){

            if(i>0 && nums[i] == nums[i-1])continue;
            int x = nums[i]+k;
            int isFound = isPresent(i+1,n-1,nums,x);

            if(isFound == n){
                return count;
            }

            if(isFound != -1){
                count++;
            }
       }

       return count;
    }
};


int main(){
    
}