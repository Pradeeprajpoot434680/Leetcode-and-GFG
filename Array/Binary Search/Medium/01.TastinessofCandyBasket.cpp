#include<bits/stdc++.h>
using namespace std;

int maximumTastiness(vector<int>& price, int k) {
    int start = INT_MAX, end;
    int n = price.size();
    int ans = 0;
    
    sort(price.begin(), price.end());

    for (int i = 1; i < price.size(); i++) {  // Start from i = 1
        start = min(start, price[i] - price[i - 1]);
    }

    end = price[n - 1] - price[0];

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int last_selected = price[0], count = 1;  // Select the first candy initially
        
        for (int i = 1; i < n; i++) {
            if (price[i] - last_selected >= mid) {
                count++;
                last_selected = price[i];
            }
            if (count == k) {
                break;
            }
        }

        if (count >= k) {
            ans = mid; 
            start = mid + 1;
        } else {
            end = mid - 1;  
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {13, 5, 1, 8, 21, 2};
    int k = 3;
    cout << maximumTastiness(arr, k) << endl;
    return 0;
}
