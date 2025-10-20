#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans=0;
        // if(target=="0000")return 0;
        queue<string>q;
        unordered_set<string>s;
        q.push("0000");
        s.insert("0000");
        unordered_set<string>isPresent;
        for(string s:deadends){
            isPresent.insert(s);
        }

        if(isPresent.count("0000"))return -1;

        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                string temp = q.front();
                q.pop();
                if(temp == target){
                    return ans;
                }
                // if(isPresent.count(temp))continue;
                for(int i=0; i<4; i++){
                    string add = temp;
                    add[i] = ((((add[i]-'0')+1)% 10 )+ '0');
                    if(!isPresent.count(add) && !s.count(add)){
                        q.push(add);
                        s.insert(add);
                    }
                }

                for(int i=0; i<4; i++){
                    string sub = temp;
                    sub[i] = (((((sub[i]-'0')-1)+10)% 10 )+ '0');
                    if(!isPresent.count(sub) &&  !s.count(sub) ){
                        q.push(sub);
                        s.insert(sub);
                    }
                }
            }

            ans++;

        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<string> deadends= {"0201","0101","0102","1212","2002"};
    string target= "0202";
    cout<< s.openLock(deadends, target);
}