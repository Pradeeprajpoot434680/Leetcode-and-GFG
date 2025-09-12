#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<vector<int>> ans;
set<vector<int> >s;
void f(int index,vector<int>&nums,vector<int>&temp,int prev){
    if(temp.size()>=2){
        s.insert(temp);
    }
    if(index==nums.size()){
        return;
    }

    if( prev == -1) {
        temp.push_back(nums[index]);
        f(index+1,nums,temp,index);
        temp.pop_back();
    }
    else {
        if(nums[prev] <= nums[index]){
            temp.push_back(nums[index]);
            f(index+1,nums,temp,index);
            temp.pop_back();   
        }
    }

    f(index+1,nums,temp,prev);
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int>temp;
    f(0,nums,temp,-1);
    for(auto it:s){
        ans.push_back(it);
    }
    return ans;
}

int main(){
    vector<int>nums={4,6,7,7};
    vector<vector<int>>ans=findSubsequences(nums);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}