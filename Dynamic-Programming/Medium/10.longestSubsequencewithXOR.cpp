#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> drovantila = nums;

        int totalXor = 0;
        long long sum = 0;
        int zeros = 0;
        for (int num : nums) {
            totalXor ^= num;
            sum += num;
            if (num == 0) zeros++;
        }

        if (totalXor != 0) return nums.size();

        if (sum == 0) return 0;

        return nums.size() - 1 ;
    }
};


int main(){
    Solution s;
    vector<int>nums = {2,4,2,5,6,7,4};
    cout<<s.longestSubsequence(nums);
}