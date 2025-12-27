#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:  
    int kthIndex(vector<int>& arr,int k,int size){

         int start =0;
        
         int end = size-1;
        
         int ans =size;
        
         while(start <=end){
        
            int mid = start + (end - start)/2;
        
            if(arr[mid] - mid - 1 >=k){
        
                ans = mid ;
        
                end = mid -1;
        
            }
        
            else{
        
                start = mid + 1;
        
            }
        
         }
        
         return ans + k;
        
        }

    int findKthPositive(vector<int>& arr, int k) {

        return kthIndex(arr,k,arr.size());

        

    }
    int kthMissing(vector<int> &arr, int k) {
        // code here
        return findKthPositive(arr,k);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << sol.kthMissing(arr, k) << endl; // Output: 9
    return 0;
}
