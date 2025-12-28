#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& ranks, int n, long long t) {
        long long donuts = 0;

        for (int r : ranks) {
            long long time = 0;
            long long k = 1;

            while (true) {
                time += (long long)r * k;
                if (time > t) break;
                donuts++;
                if (donuts >= n) return true;
                k++;
            }
        }
        return donuts >= n;
    }

    int minTime(vector<int>& ranks, int n) {
        long long low = 1;
        long long high = 1e14; // safe high bound
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canMake(ranks, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};


int main() {
    Solution sol;
    vector<int> ranks = {1, 2, 3};
    int n = 10;
    cout << sol.minTime(ranks, n) << endl;
    return 0;
}