#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        int ans =0;
        for(auto it:m){
            if(it.second % k == 0){
                ans += (it.second*it.first);
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6};
    int k = 2;
    int result = sol.sumDivisibleByK(nums, k);
    cout << "Sum of elements with frequency divisible by " << k << " is: " << result << endl;   
}