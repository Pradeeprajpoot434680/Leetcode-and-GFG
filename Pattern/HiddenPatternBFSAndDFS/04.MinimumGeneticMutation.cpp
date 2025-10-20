#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>validBank;
        for(string str:bank){
            validBank.insert(str);
        }
        if(! validBank.count(endGene))return -1;

        queue<string>q;
        unordered_set<string>visited;

        q.push(startGene);
        visited.insert(startGene);
        string ch = "ACGT";
        int ans=0;
        while(!q.empty()){
            int n = q.size();

            while(n--){
               string temp = q.front();
               q.pop();
               if(temp==endGene){
                return ans;
               }
               for(int i=0; i<temp.size(); i++){

                for(int j=0; j<ch.size(); j++){

                    if(temp[i]==ch[j])continue;
                    string mutated = temp;
                    mutated[i] = ch[j];

                    if(validBank.count(mutated) && !visited.count(mutated)){
                        visited.insert(mutated);
                        q.push(mutated);
                    }
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
    string startGene= "AACCGGTT";
    string endGene= "AAACGGTA";
    vector<string> bank= {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout<< s.minMutation(startGene, endGene, bank);
}