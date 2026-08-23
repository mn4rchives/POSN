#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int unsigned long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    getline(cin, s);

    int count=0, po=0;
    vector<int>v(26, 0);
    for(char &c:s){
        c = tolower(c);
        int x = c-'a';
        if(c-'a'>=0 and c-'a'<=25){
            if(x==0){
                v[x]++;
            }else{
                v[x]=v[x-1]+v[x];
                }
        }
    }
    
    
    cout << v[25];
    return 0;  
}