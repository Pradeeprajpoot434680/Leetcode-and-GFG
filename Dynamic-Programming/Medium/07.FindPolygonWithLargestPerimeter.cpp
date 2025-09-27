#include<bits/stdc++.h>
using namespace std;
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];

        }

        long long ans=0;
        for(int i=n-1; i>0; i--){
           if(nums[i]<prefixSum[i-1]){
            for(int j=0; j<=i; j++){
                ans+=nums[j];
            }
            return ans;
           }

        }

        return ans==0?-1:ans;
    }

    int main(){
        vector<int>arr={4,3,6,1,2,3,5,7};
        cout<<largestPerimeter(arr);
        return 0;
    }