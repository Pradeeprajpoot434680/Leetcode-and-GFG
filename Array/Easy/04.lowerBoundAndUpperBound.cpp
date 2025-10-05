#include<bits/stdc++.h>
using namespace std;
#include<algorithm>
int main(){
    // int n;
    // cout<<"Enter n:";
    // cin>>n;
    int arr[6]={1, 3 ,4, 6, 8, 9};
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    sort(arr,arr+6);
    for(int i:arr){
        cout<<i<<" ";
    }

    int * ptr = upper_bound(arr,arr+6,3);
    cout<<"upper bound is:"<<*ptr<<endl;
    int *ptr1 = lower_bound(arr,arr+6,3);
    cout<<"Lower bound is:"<<(*ptr1);
    vector<int>nums={4,2,7,5,3,8,1};
    int n = nums.size();
    sort(nums.begin(),nums.end());
    auto it = upper_bound(nums.begin(),nums.end(),4);
    cout<<"Upper bound for vector is :"<<(*it);
    auto it1 = lower_bound(nums.begin(),nums.end(),9);
    cout<<"Lower bound for the vector is:"<<(*it1);

}