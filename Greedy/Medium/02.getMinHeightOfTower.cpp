#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    // code here
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int longest = arr[n-1];
    int shortest = arr[0];
    
    int ans = longest - shortest;
    
    for(int i=1; i<n; i++){
        longest = max(arr[n-1]-k,arr[i-1]+k);
        shortest = min(arr[0]+k,arr[i]-k);
        
        
        ans = min(ans,longest - shortest);
    }
    
    return ans;
}

int main(){
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    cout<<getMinDiff(arr,k);
    return 0;
}