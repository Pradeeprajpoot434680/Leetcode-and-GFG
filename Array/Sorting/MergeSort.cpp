#include<iostream>
#include<vector>
using namespace std;

    void conqure(vector<int>&arr,int start,int mid,int end){
        //store the sorted element
        
        vector<int>temp(end - start+1);
        int left = start;
        int right = mid+1;
        
        int index =0;
        while(left <= mid && right <=end)
        {
            if(arr[left] <= arr[right]){
                temp[index] = arr[left];
                left++;
            }
            else{
                temp[index]=arr[right];
                right++;
            }
            index++;
        }
        
        while(left <= mid){
            temp[index] = arr[left];
            index++;
            left++;
        }
        while(right<=end){
            temp[index] = arr[right];
            right++;
            index++;
        }
        
        index=0;
        
        for(int i=start; i<=end;i++){
            arr[i] = temp[index];
            index++;
        }
    }
    
    void divide(vector<int>&arr,int start,int end){
        if(start == end)return;
        
        int mid = start + (end - start)/2;
        
        divide(arr,start,mid);
        divide(arr,mid+1,end);
        conqure(arr,start,mid,end);
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        divide(arr,l,r);
    }

int main(){
  vector<int>arr={16,3,2,6,7,2,1};
  mergeSort(arr,0,arr.size());
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
