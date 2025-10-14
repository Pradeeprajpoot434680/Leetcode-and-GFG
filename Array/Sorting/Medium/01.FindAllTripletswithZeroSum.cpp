#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        vector<pair<int,int>> temp;
        for (int i = 0; i < n; i++) temp.push_back({arr[i], i});
        sort(temp.begin(), temp.end());

        for (int i = 0; i < n - 2; i++) {
            int start = i + 1;
            int end = n - 1;

            while (start < end) {
                int sum = temp[i].first + temp[start].first + temp[end].first;

                if (sum == 0) {
                    int curStartVal = temp[start].first;
                    int curEndVal   = temp[end].first;

                   
                    vector<int> trip = {temp[i].second, temp[start].second, temp[end].second};
                    sort(trip.begin(), trip.end());
                    ans.push_back(trip);

                   
                    int nextStart = start + 1;
                    while (nextStart < end && temp[nextStart].first == curStartVal) {
                        vector<int> dupTrip = {temp[i].second, temp[nextStart].second, temp[end].second};
                        sort(dupTrip.begin(), dupTrip.end());
                        ans.push_back(dupTrip);
                        nextStart++;
                    }

                   
                    int nextEnd = end - 1;
                    while (nextEnd > start && temp[nextEnd].first == curEndVal) {
                        vector<int> dupTrip = {temp[i].second, temp[start].second, temp[nextEnd].second};
                        sort(dupTrip.begin(), dupTrip.end());
                        ans.push_back(dupTrip);
                        nextEnd--;
                    }

                    // move pointers
                    start++;
                    end--;
                }
                else if (sum < 0) start++;
                else end--;
            }
        }

        // Remove duplicate index triplets
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> result = sol.findTriplets(arr);
    for (const auto& triplet : result) {
        cout << "[";
        for (int index : triplet) {
            cout << index << " ";
        }
        cout << "] ";
    }
    cout << endl;
}