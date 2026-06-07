#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    vector<int>v(n);
    int sum=0;
    for(int i=0; i<n; i++) {
        cin>>v[i];
        sum+=v[i];
    }

    sort(v.begin(), v.end());

    
    for(int i=n-4; i>=0; i-=4){
        sum-=v[i];
    }

    cout << sum;

    return 0;  
}