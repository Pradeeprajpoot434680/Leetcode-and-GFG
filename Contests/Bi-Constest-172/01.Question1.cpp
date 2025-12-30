// Q1. Minimum Number of Operations to Have Distinct Elements
#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        int dup  =0;
        for(int i:nums){
            if(m[i] == 1){
                dup++;
            }
            m[i]++;
        }

        int index  = 0;
        int op = 0;
        int n = nums.size();
        if(dup==0)return 0;
        while(index < n){
            
            
            if(dup > 0){
                for(int i=index; i<min(index+3,n); i++){
                    if(dup == 0){
                        return op+1;
                    }

                    m[nums[index]]--;

                    if(m[nums[index]]==0){
                        m.erase(nums[index]);
                    }
                    else if(m[nums[index]]==1){
                        dup--;
                    }
                }
            }
            op++;
            index += 3;
            
        }

        return op;
    }
};
int main(){
    Solution s;
    vector<int>arr={3,8,3,6,5,8};
    cout<<s.minOperations(arr);
}