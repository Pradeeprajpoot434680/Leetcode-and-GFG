#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#include <climits>

int assignHole(vector<int>& mices, vector<int>& holes) {
    // code here
    sort(mices.begin(),mices.end());
    sort(holes.begin(),holes.end());
    
    int n = holes.size();
    int ans = INT_MIN;
    
    for(int i=0; i<n; i++){
        ans = max(ans,abs(mices[i]-holes[i]));
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> mices(n);
    vector<int> holes(n);
    for (int i = 0; i < n; i++) {
        cin >> mices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> holes[i];
    }
    cout << assignHole(mices, holes) << endl;
    return 0;
}