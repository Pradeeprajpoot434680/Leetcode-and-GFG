#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>m;
        set<int>s;
        vector<int>ans(rains.size(),1);
        for(int i=0; i<rains.size(); i++){
            int lake = rains[i];
            if(lake==0){
                s.insert(i);
            }
            else {
                ans[i]=-1;
                if(m.count(lake)){
                    auto it = s.lower_bound(m[lake]);
                    if(it == s.end()){
                        return {};
                    }
                    int day = *it;
                    ans[day]=lake;

                    s.erase(it);
                }
                m[lake]=i;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> rains = {1,2,0,0,2,1};
    vector<int> result = sol.avoidFlood(rains);
    for (int day : result) {
        cout << day << " ";
    }
    cout << endl;
}