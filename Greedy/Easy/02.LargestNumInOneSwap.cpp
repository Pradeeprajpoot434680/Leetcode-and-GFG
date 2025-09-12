#include<iostream>
#include<string>
#include<vector>

using namespace std;

string largestSwap(string &s) {
    vector<int>last(10,0);
    int n = s.size();
    for(int i=0; i<n; i++){
        last[s[i]-'0']=i;
    }
    for(int i=0; i<n; i++){
        
        for(int d =9; d > s[i]-'0'; d--){
            if(last[d] > i){
                char t = s[i];
                s[i] = s[last[d]];
                s[last[d]] = t;
                return s;
            }
        }
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<largestSwap(s);
    return 0;
}
// Input: "2736"
// Output: "7236"