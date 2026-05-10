#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>decl;
vector<int>dp;
const int INF=9e10;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; 
    cin>>n;

    decl.resize(n+1);
    dp.assign(n+1, -INF);

    for(int i=0; i<n; i++){
        cin>>decl[i+1];
    }

    dp[0]=0;
    for(int i=1; i<=n; i++){
        if(i<2) {
            dp[1] = max(0LL, decl[i]);
            // cout << "dp=" << dp[i] << "\n";
            continue;
        }
        dp[i]=max(dp[i-2]+decl[i], dp[i-1]);
        // cout << "dp=" << dp[i] << "\n";
    }

    cout << dp[n];


    return 0;  
}