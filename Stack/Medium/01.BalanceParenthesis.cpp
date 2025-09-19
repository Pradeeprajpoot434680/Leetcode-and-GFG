#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int minParentheses(string& s) {
    // code here
    stack<char>st;
    int count=0;
    for(int i=0; i<s.size(); i++){
        if(st.empty() && s[i]==')'){
            count++;
        }
        else{
            if(s[i]=='('){
                st.push('(');
            }
            else
            {
                if(st.top()=='(' && s[i]==')'){
                    st.pop();
                }
            }
        }
    }
    
    return count + st.size();
}

int main(){
    string s = "()(())()(()))))))()";
    cout<<minParentheses(s);
}