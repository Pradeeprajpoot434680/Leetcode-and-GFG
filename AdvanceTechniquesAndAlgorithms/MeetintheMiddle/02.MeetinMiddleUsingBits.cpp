#include<bits/stdc++.h>
using namespace std;

void getSubSums(vector<int>arr,vector<long long>&sum){
    int n = arr.size();
    long long total = 1<<n;
    sum.reserve(1<<20);
    for(long long mask=0; mask<total; mask++){
        long long addition=0;

        for(int i=0; i<n; i++){
            if( mask & (1<<i))addition+= arr[i]; //(1<<i) check i th bit set or not
        }
        sum.push_back(addition);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> firstHalf(arr.begin(), arr.begin() + n / 2);
    vector<int> secondHalf(arr.begin() + n / 2, arr.end());


    vector<long long> sums1, sums2;
    getSubSums(firstHalf, sums1);
    getSubSums(secondHalf, sums2);

    sort(sums2.begin(),sums2.end());
    long long ans = 0;
    for (long long s1 : sums1) {
        long long need = x - s1;
        auto range = equal_range(sums2.begin(), sums2.end(), need);
        ans += (range.second - range.first);
    }

    cout << ans << "\n";
    return 0;
}