#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i%2==0){
                sum+=nums[i];
            }
            else{
                sum-= nums[i];
            }
        }

        return sum;
    }
};

int main(){
    Solution s;
    vector<int>nums = {4,2,5,7,8,2};
    cout<<s.alternatingSum(nums);
}

