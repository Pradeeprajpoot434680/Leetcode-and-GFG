//Count elements less than or equal to k in a sorted rotated array


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        if (n == 0) return 0;

        // 1. Find pivot (index of minimum element)
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > arr[r])
                l = m + 1;
            else
                r = m;
        }
        int pivot = l;  // smallest element index

        // Helper to access array as if fully sorted
        auto get = [&](int idx) {
            return arr[(idx + pivot) % n];
        };

        // 2. upper_bound on the virtual sorted array
        l = 0; 
        r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (get(m) <= x)
                l = m + 1;
            else
                r = m;
        }

        return l;  
    }
};

int main(){
    
}