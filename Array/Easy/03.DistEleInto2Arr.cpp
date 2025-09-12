#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<int> resultArray(vector<int>& nums) {
    vector<int>arr1,arr2;
    for(int i:nums){
    bool flag = 0;
    if(arr1.size()>0 && arr2.size()>0){
        if(arr1[arr1.size()-1] > arr2[arr2.size()-1]){
            flag=1;
        }
    }
    else {
        if(arr1.size()==0){
            arr1.push_back(i);
        }
        else if(arr2.size()==0){
            arr2.push_back(i);
        }
        continue;
    }

    if(flag){
        arr1.push_back(i);
    }else
    {
        arr2.push_back(i);
    }
    }

    vector<int>ans;
    for(int i:arr1)ans.push_back(i);
    for(int i:arr2)ans.push_back(i);

    return ans;
}

int main(){
    vector<int>nums={1,2,3,4,5};
    vector<int>ans=resultArray(nums);
    for(int i:ans)cout<<i<<" ";
    return 0;
}   