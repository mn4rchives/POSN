#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;cin>>n>>k;
    vector<int>v(n);
    vector<int>dp(n, -1);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    dp[0]=0;

    for(int i=1; i<n; i++){
        for(int j=0; j<k; j++){
            if(i-(j+1)<0) break;
            if(dp[i]==-1){
                dp[i] =  dp[i-(j+1)]+ abs(v[i]-v[i-(j+1)]);
                continue;
            }
            dp[i]=min(dp[i-(j+1)]+ abs(v[i]-v[i-(j+1)]), dp[i]);
        }
    }

    cout << dp[n-1];

    return(0);
}