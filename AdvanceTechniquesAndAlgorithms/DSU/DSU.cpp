#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&parent){
    if(x==parent[x]){
        return x;
    }

    return find(parent[x],parent);
}
void combine(int u,int v,vector<int>&parent){
    if(parent[v]==parent[u]){
        return;
    }

    parent[v] = u;
}
int main(){
    int n = 8;
    vector<int>parent(n);
    for(int i=0; i<n; i++){
        parent[i]= i;
    }
    combine(0,1,parent);
    combine(2,3,parent);
    combine(4,5,parent);
    combine(6,7,parent);
    combine(0,3,parent);
    combine(3,6,parent);

    cout<<"Parent of 3:"<<find(3,parent);
    cout<<"Parent of 6:"<<find(6,parent);
    cout<<"Parent of 7:"<<find(7,parent);
}