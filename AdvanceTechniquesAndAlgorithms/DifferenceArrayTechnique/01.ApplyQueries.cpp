#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={0,0,0,0,0,0,0,0,0,0};
    vector<vector<int>>queries={{2,3,5},{1,1,7},{3,4,1}};// {startIndex,endIndex,incValue}
    int n=arr.size();

    for(int i=0; i<queries.size(); i++){
        int s = queries[i][0];
        int e = queries[i][1];
        int val = queries[i][2];

        arr[s] += val;
        if(e+1 < n){
            arr[e+1] -= val;
        }
    }

    // take prefix sum

    for(int i=1; i<n; i++){
        arr[i] = arr[i]+arr[i-1];
    }

    for(int i:arr){
        cout<<i<<"  ";
    }
    return 0;
}