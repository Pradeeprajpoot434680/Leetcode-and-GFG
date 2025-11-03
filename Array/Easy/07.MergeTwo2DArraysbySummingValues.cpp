#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> map;

        // Add all elements from nums1 to the map
        for (const auto& num : nums1) {
            int key = num[0];
            int value = num[1];
            map[key] = value;
        }

        // Add elements from nums2 to the map, merging values if the key already exists
        for (const auto& num : nums2) {
            int key = num[0];
            int value = num[1];
            if (map.find(key) != map.end()) {
                map[key] += value; // Merge the values
            } else {
                map[key] = value; // Add new key-value pair
            }
        }

        // Convert the map to a 2D vector for the result
        vector<vector<int>> result;
        for (const auto& entry : map) {
            result.push_back({entry.first, entry.second});
        }

        // Sort result by the key
        sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> nums1 = {{1, 3}, {2, 4}, {3, 5}};
    vector<vector<int>> nums2 = {{2, 1}, {3, 4}, {4, 6}};

    vector<vector<int>> result = solution.mergeArrays(nums1, nums2);

    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}
