#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    vector<int>v(n), dp(n+1);

    for(int i=0; i<n; i++){
        cin>>v[i];
        dp[i] = (i+1)*(i+1);
    }

    dp[n] = (n+1)*(n+1);

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(v[i-1]<v[j-1]) continue;
            dp[i] = min(dp[i], dp[j]+((i-j)*(i-j)));
        }
    }

    // for(int i=0; i<=n; i++){
    //     debug(dp[i]);
    // }
    cout << dp[n];

    return 0;  
}