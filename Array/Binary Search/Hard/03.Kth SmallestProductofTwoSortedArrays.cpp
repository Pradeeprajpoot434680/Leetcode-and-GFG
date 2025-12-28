#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
     using ll = long long;

        long long countLE(const vector<int>& A, const vector<int>& B, long long x) {
            long long cnt = 0;
            int m = B.size();

            for (int a : A) {
                if (a > 0) {
                    
                    long long val = floor((double)x / a);
                    cnt += upper_bound(B.begin(), B.end(), val) - B.begin();
                } else if (a < 0) {
                    
                    long long val = ceil((double)x / a);
                    cnt += B.end() - lower_bound(B.begin(), B.end(), val);
                } else {
                    // a == 0
                    if (x >= 0) cnt += m;
                }
            }
            return cnt;
        }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
         ll lo = -1e18, hi = 1e18;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (countLE(nums1, nums2, mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1, 7};
    vector<int> nums2 = {3, 4};
    long long k = 3;
    cout << sol.kthSmallestProduct(nums1, nums2, k) << endl;
    return 0;
}