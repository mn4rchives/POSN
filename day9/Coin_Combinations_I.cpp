#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
const int mod=1e9+7;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin>>n>>x;

    vector<int>v(n), dp(x+1, 0);

    dp[0]=1;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i-v[j]<0) continue;
            dp[i]=(dp[i-v[j]]+dp[i])%mod;
        }
    }

    cout<<dp[x];

    return 0;  
}