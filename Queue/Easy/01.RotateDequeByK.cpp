#include<bits/stdc++.h>
using namespace std;
 void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type==1){
            while(k--){
                if(!dq.empty()){
                    int x = dq.back();
                    dq.pop_back();
                    dq.push_front(x);
                    
                }
                
            }
        }
        else{
            while(k--){
                if(!dq.empty()){
                    
                    int x= dq.front();
                    dq.pop_front();
                    dq.push_back(x);
                }
            }
        }
    }

    int main(){
        deque<int> dq = {1,2,3,4,5};
        int type = 1; // 1 for right rotation, 0 for left rotation
        int k = 2; // number of rotations
        rotateDeque(dq, type, k);
        for(int x : dq){
            cout << x << " ";
        }
        return 0;   
    }