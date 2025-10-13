
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> count(26, 0);

            for (int j = i; j < n; j++) {
                count[s[j] - 'a']++;

                // check if substring s[i..j] is "balanced"
                bool isGood = true;
                int prev = 0;
                bool isFirst = true;

                for (int p = 0; p < 26; p++) {
                    if (count[p] != 0) {
                        if (isFirst) {
                            prev = count[p];
                            isFirst = false;
                        } else if (count[p] != prev) {
                            isGood = false;
                            break;
                        }
                    }
                }

                if (isGood) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
int main(){
    Solution sol;
    string s = "ababbccddeee";
    int result = sol.longestBalanced(s);
    cout << "Length of the longest balanced substring: " << result << endl;
}