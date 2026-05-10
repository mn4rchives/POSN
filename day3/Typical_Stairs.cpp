#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool>dang;
vector<int>dp;
const int mod=1e9+7;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    dang.assign(n+1, false);
    dp.assign(n+1, 0);

    dp[0]=1;
    for(int i=0; i<m; i++){
        int c; cin>>c;
        dang[c]=true;
    }

    for(int i=1; i<=n; i++){
        if(dang[i]) continue;
        if(i<2){
            dp[i]=1;
            continue;
        }
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }

    cout << dp[n];

    return 0;  
}