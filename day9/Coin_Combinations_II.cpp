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

    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j-v[i]<0) continue;
            dp[j] = (dp[j]+dp[j-v[i]])%mod;
        }
    }

    cout<<dp[x];

    return 0;  
}