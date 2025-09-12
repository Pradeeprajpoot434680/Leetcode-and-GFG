#include<iostream>
#include<vector>
using namespace std;

int getSingle(vector<int>& arr) {
    // code here
    int ans =0;
    for(int i:arr){
        ans ^= i;
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4};
    cout << "The single number is: " << getSingle(arr) << endl;
    return 0;
}
// Time Complexity: O(N)
// Space Complexity: O(1)