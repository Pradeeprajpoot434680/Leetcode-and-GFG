#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max(begin(nums), end(nums));
        vector<int>freq(maxEl + 1, 0);

        for(int ele:nums){
            freq[ele]++;
        }

        //cumulativefreq
        for(int i=1; i<=maxEl; i++){
            freq[i] += freq[i-1];
        }
        int result=0;
        for(int target=0; target<=maxEl;target++){
            if(freq[target]==0)continue;

            int  leftNum = max(0,target-k);
            int rightNum = min(target+k,maxEl);

            int totalCount = freq[rightNum]-freq[leftNum-1];

            int targetCount = freq[target]-freq[target-1];

            int needConversion = totalCount - targetCount;

            int maxPossibleConversion = targetCount + min(needConversion,numOperations);

            result = max(result, maxPossibleConversion);
        }
        
        return result;
    }

};


int main(){
    Solution s;
    vector<int>nums= {1,2,4};
    int k=5;
    int numOperations=1;
    cout<< s.maxFrequency(nums, k, numOperations);
}