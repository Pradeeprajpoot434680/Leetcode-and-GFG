#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> palindromicSubstr(string &s) {
        int n = s.size();
        unordered_set<string> st;

        // Function to expand around center
        auto expand = [&](int l, int r){
            while(l >= 0 && r < n && s[l] == s[r]){
                st.insert(s.substr(l, r - l + 1));
                l--;
                r++;
            }
        };

        // Odd length palindromes
        for(int i = 0; i < n; i++){
            expand(i, i);
        }

        // Even length palindromes
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1])
                expand(i, i+1);
        }

        // Convert set → vector
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};
