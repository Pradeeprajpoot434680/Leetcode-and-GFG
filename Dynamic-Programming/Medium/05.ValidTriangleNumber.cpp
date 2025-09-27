#include <bits/stdc++.h>
using namespace std;
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1; i>=0; i--){
            int ele = nums[i];
            int start=0;
            int end = i-1;
            while(start<end){
                if(nums[end]==0){
                    end--;
                    continue;
                }
                if(nums[start]==0){
                    start++;
                    continue;
                }
                
                if(nums[start] + nums[end] > ele ){
                    ans+=(end-start);
                    end--;
                }
                else{
                    start++;
                }
            }
        }

        return ans;
    }

    int main(){
        vector<int> nums = {2,2,3,4};
        cout<<triangleNumber(nums);
        return 0;
    }