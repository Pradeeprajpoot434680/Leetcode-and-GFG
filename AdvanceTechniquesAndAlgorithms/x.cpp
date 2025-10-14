// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// void helper(int index, int sum, const vector<int>& arr, unordered_map<int, int>& m) {
//     int n = arr.size();
//     if (index == n) {
//         m[sum]++;
//         return;
//     }
//     // pick
//     helper(index + 1, sum + arr[index], arr, m);
//     // not pick
//     helper(index + 1, sum, arr, m);
// }

// int main() {
//     ios::sync_with_stdio(false);//for input output optimization
//     cin.tie(nullptr);

//     int n;
//     long long x;
//     cin >> n >> x;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     vector<int> firstHalf(arr.begin(), arr.begin() + n / 2);
//     vector<int> secondHalf(arr.begin() + n / 2, arr.end());

//     unordered_map<int, int> first;
//     unordered_map<int, int> second;

//     helper(0, 0, firstHalf, first);
//     helper(0, 0, secondHalf, second);

//     long long ans = 0;
//     for (auto& it : first) {
//         long long goal = x - it.first;
//         if (second.find(goal) != second.end()) {
//             ans += 1LL * it.second * second[goal];
//         }
//     }

//     cout << ans << "\n";
//     return 0;
// }
