#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<string> generateBinary(int n) {
//     vector<string> result;
//     int total = 1 << n; // 2^n combinations

//     for (int i = 0; i < total; ++i) {
//         string binary;
//         for (int j = n - 1; j >= 0; --j) {
//             binary += (i & (1 << j)) ? '1' : '0';
//         }
//         result.push_back(binary);
//     }

//     return result;
// }
 
vector<string> generateBinary1(int n) {
        vector<string> result(n);
        result[0] = "1";
        for(int i = 2;i<=n;i++){
            result[i-1] = result[(i/2)-1];
            if(i%2 == 0){
                result[i-1].push_back('0'); 
            }
            else{
                result[i-1].push_back('1'); 
            }
        }
        
        return result;
    }
        string f(int n){
        int num = n;
        string ans="";
        while(num>0){
            int x = num%2;
            num/=2;
            ans= to_string(x)+ans;
        }
        
        return ans;
    }
    vector<string> generateBinary3(int n) {
        // code here
        vector<string>ans;
        for(int i=1; i<=n; i++){
            ans.push_back(f(i));
        }
        
        return ans;
    }
int main(){
    int n = 4; // Change this value to generate binary numbers of different lengths
    vector<string> binaries = generateBinary1(n);
    for (const string& binary : binaries) {
        cout << binary << endl;
    }
    return 0;
}