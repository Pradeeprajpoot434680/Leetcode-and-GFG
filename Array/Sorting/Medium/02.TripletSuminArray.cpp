#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n-2; i++){
            int x = arr[i];
            int start=i+1;
            int end = n-1;
            
            while(start<end){
                if(x + arr[start]+arr[end] == target){
                    return 1;
                }
                else if(x + arr[start]+arr[end] < target){
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        
        return 0;
    }
};



int main(){
    Solution sol;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int target = 18;
    bool result = sol.hasTripletSum(arr,target);
    cout << (result ? "True" : "False") << endl;
}