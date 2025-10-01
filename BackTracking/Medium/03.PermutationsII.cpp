#include<bits/stdc++.h>
using namespace std;
void allPermute(vector<vector<int>>&ans,vector<int>& arr,int index)
    {
        if(index == arr.size())
        {
            ans.push_back(arr);
            return;
        }
        vector<int> use(21,0);
        for(int i= index; i<arr.size(); i++)
        {
            if(use[arr[i] + 10] ==0)
            {
                use[arr[i]+10] = 1;
                swap(arr[index],arr[i]);
                allPermute(ans,arr,index+1);
                swap(arr[index],arr[i]);
                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        allPermute(ans,nums,0);
        return ans;

        
    }



    int main(){
        vector<int>arr={1,2,3,4};
        vector<vector<int>> result = permuteUnique(arr);
        for(int i=0; i<result.size(); i++){
            for(int j=0; j<result[i].size(); j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }