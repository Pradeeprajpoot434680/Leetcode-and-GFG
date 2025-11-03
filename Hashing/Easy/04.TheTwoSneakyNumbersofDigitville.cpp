#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, bool> m;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]]) {
                ans.push_back(nums[i]);
                m[nums[i]] = false;
            } else {
                m[nums[i]] = true;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 2, 5, 1};
    vector<int> sneakyNumbers = solution.getSneakyNumbers(nums);

    for (int num : sneakyNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
