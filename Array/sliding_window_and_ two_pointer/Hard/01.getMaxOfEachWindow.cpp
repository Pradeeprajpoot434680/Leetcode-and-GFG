#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class maxQueue {
private:
    queue<int> q;
    deque<int> dq;

public:
    void push(int value) {
        q.push(value);

        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }

        dq.push_back(value);
    }

    void pop() {
        if (!q.empty()) {
            int front = q.front();
            q.pop();
            if (!dq.empty() && dq.front() == front) {
                dq.pop_front();
            }
        }
    }

    int max() {
        if (!dq.empty()) {
            return dq.front();
        }
        throw runtime_error("Queue is empty");
    }

    bool empty() {
        return q.empty();
    }
};

class Solution {
public:
    maxQueue q;

    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }

        for (int i = k; i < n; i++) {
            ans.push_back(q.max());

            q.pop();

            q.push(nums[i]);
        }

        ans.push_back(q.max());

        return ans;
    }
};


int main(){
    
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int n = nums.size();
    int k = 3;
    vector<int> ans = s.max_of_subarrays(nums, n, k);
    cout<<"The maximum of each subarray of size k is: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}