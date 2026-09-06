#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
const int INF=4e18;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin>>n>>k;

    vector<int>v(n);
    vector<int>dp(n+1, INF);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    dp[0]=0;
    dp[1]=0;


    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-(j+1)<0) break;
            dp[i] = min(dp[i], abs(v[i-1]-v[i-(j+1)])+dp[i-j]);
        }
    }

    cout << dp[n];



    return 0;  
}