#include<iostream>
using namespace std;
#include<string>
#include<vector>
string sortVowels(string &s) {
    vector<int>lower(26,0);
    vector<int>upper(26,0);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            lower[s[i]-'a']++;
        }
        else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
            upper[s[i]-'A']++;
        }
    }

    for(int i=0; i<s.size(); i++)
    {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
            for(int j=0; j<26; j++)
            {
                if(upper[j])
                {
                    s[i] = 'A' + j;
                    upper[j]--;
                    goto next_iteration;
                }
            }
            for(int j=0; j<26; j++)
            {
                if(lower[j])
                {
                    s[i] = 'a' + j;
                    lower[j]--;
                    goto next_iteration;
                }
            }
            }
            next_iteration:
            continue;
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<sortVowels(s);
}