#include<bits/stdc++.h>     
using namespace std;

class Solution {
public:
    int n;
    int countPairsSmallorEqualToDistance(vector<int>&arr,int distance){
        int i=0;
        int j = 1;
        int count=0;
        while(i<n && j<n){
            if(abs(arr[i]-arr[j]) <= distance){
                count+= (j-i);
                j++;
            }
            else {
                i++;
            }
        }

        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        int maxEle = *max_element(nums.begin(),nums.end());

        int minEle = *min_element(nums.begin(),nums.end());

        int start = 0;
        int end = maxEle  - minEle;
        int ans=end;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(countPairsSmallorEqualToDistance(nums,mid) >= k){
                ans= mid;
                end = mid-1;
            }
            else {
                start =mid+1;
            }
        }


        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1};
    int k = 1;
    cout << sol.smallestDistancePair(nums, k) << endl;
    return 0;
}