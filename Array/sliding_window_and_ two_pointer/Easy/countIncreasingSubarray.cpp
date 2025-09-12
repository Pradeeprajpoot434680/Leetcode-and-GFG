#include<iostream>
#include<vector>
using namespace std;

int countIncreasing(vector<int>& arr) {
    // code here.
    int count=0;
    int starting =0;
    int i=0;
    for( i=0; i<arr.size()-1; i++){
        
        if(arr[i] >= arr[i+1]){
            int x = i-starting+1;
            if(x>=2){
                
            count+=((x)*(x-1)/2);
            }
            starting = i+1;
        }
    }
    int x = i-starting+1;
    if(x>=2){
        
    count+=((x)*(x-1)/2);
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,2,4};
    cout<<countIncreasing(arr);
    return 0;
}