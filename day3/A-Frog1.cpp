#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define int long long
vector<int>co;
vector<int>dp;
const int INF=4e9;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    co.resize(n+1);
    dp.assign(n+1, INF);
    dp[0]=0;
    dp[1]=0;

    for(int i=0; i<n; i++){
        cin>>co[i+1];
    }

    co[0]=0;

    for(int i=2; i<=n; i++){
        int a=abs(co[i]-co[i-1]);
        int b=abs(co[i]-co[i-2]);
        // cout << "a=" << a << "\n";
        dp[i]=min(a+dp[i-1], b+dp[i-2]);
    }

    cout << dp[n];


    return 0;  
}