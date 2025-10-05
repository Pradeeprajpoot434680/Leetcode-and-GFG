#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
    void solve(int index, int prev, int value, string newString, string &s, int &target) {
        if (index == s.size()) {
            if (value == target) {
                ans.push_back(newString);
            }
            return;
        }
    
        int n = 0;
        string temp = "";
        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (s[index] == '0' && i > index) {
                break;
            }
            n = n * 10 + (s[i] - '0');
            
            if (index == 0) {
                solve(i + 1, n, n, temp, s, target);
            } else {
                solve(i + 1, n, value + n, newString + "+" + temp, s, target);
                solve(i + 1, -n, value - n, newString + "-" + temp, s, target);
                solve(i + 1, prev * n, value - prev + (prev * n), newString + "*" + temp, s, target);
            }
        }
    }

vector<string> findExpr(string &s, int target) {
    ans.clear();
    solve(0, 0, 0, "", s, target);
    return ans;
}

int main(){
    string s="58824";
    vector<string>ans = findExpr(s,23);
    for(auto it:ans){
        cout<<it<<endl;
    }
}