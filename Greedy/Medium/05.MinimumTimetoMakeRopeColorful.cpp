#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int prev = 0;
        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[prev]) {
                if(neededTime[prev] < neededTime[i]) {
                    ans += neededTime[prev];
                    prev = i;
                } else {
                    ans += neededTime[i];
                }
            } else {
                prev = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string colors = "aabbcc";
    vector<int> neededTime = {1, 2, 3, 4, 5, 6};
    
    int result = sol.minCost(colors, neededTime);
    cout << "Minimum cost: " << result << endl;  // Output: 9
    return 0;
}
