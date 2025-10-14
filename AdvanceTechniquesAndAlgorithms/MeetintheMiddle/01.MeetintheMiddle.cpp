#include <bits/stdc++.h>
using namespace std;

void helper(int index, long long sum, const vector<int>& arr, unordered_map<long long, int>& m) {
    int n = arr.size();
    if (index == n) {
        m[sum]++;
        return;
    }
    helper(index + 1, sum + arr[index], arr, m); // pick
    helper(index + 1, sum, arr, m);              // not pick
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> firstHalf(arr.begin(), arr.begin() + n / 2);
    vector<int> secondHalf(arr.begin() + n / 2, arr.end());

    unordered_map<long long, int> first;
    unordered_map<long long, int> second;

    helper(0, 0, firstHalf, first);
    helper(0, 0, secondHalf, second);

    long long ans = 0;
    for (auto &it : first) {
        long long goal = x - it.first;
        if (second.find(goal) != second.end()) {
            ans += 1LL * it.second * second[goal];
        }
    }

    cout << ans << "\n";
    return 0;
}
