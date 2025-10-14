#include <bits/stdc++.h>
using namespace std;
class Solution {

  public:

    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        long long count = 0;
        vector<long long>nums;
        for(int i=0; i<n; i++)nums.push_back(arr[i]);
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-2; i++){
           
            
            int start =i+1; 
            int end = n-1;
            while(start <= end){
                
               long long temp = arr[start] + arr[i] + arr[end];
               if(temp < sum){
                   count+=(end-start);
                   start++;
               }
               else
               {
                   end--;
               }
            }
            
        }
        return count;
    }
};

int main(){
    Solution sol;
    long long arr[] = {5,1,3,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    long long sum = 12;
    long long result = sol.countTriplets(n,sum,arr);
    cout << result << endl;
}