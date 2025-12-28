#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static const int MOD = 1'000'000'007;

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, ans = 0;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i++];
            }
            else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j++];
            }
            else {
               
                ans += max(sum1, sum2) + nums1[i];
                sum1 = 0;
                sum2 = 0;
                i++; j++;
            }
        }

        while (i < n) sum1 += nums1[i++];
        while (j < m) sum2 += nums2[j++];

        ans += max(sum1, sum2);

        return ans % MOD;
    }
};


int main(){
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 3, 4};
    cout << sol.maxSum(nums1, nums2) << endl;
    return 0;
}