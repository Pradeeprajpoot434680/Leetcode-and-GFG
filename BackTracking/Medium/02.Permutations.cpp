#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void allPermute( vector<vector<int>>&ans,vector<int>&arr,int index)
    {
        if(index == arr.size())
        {
            ans.push_back(arr);
            return;
        }
        for(int i= index ; i<arr.size(); i++)
        {
            swap(arr[i],arr[index]);
            allPermute(ans,arr,index + 1);
            swap(arr[i],arr[index]);

        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index =0;
        allPermute(ans,nums,index);
        return ans;

        
        
    }
};

int main(){
    Solution s;
    vector<int>arr={1,2,3,4};
    s.permute(arr);
}