#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin>>n>>x;

    vector<int>h(n), s(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    vector<vector<int>>dp(n+1, vector<int>(x+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(j>=h[i-1]){
                dp[i][j]=max(s[i-1]+dp[i-1][j-h[i-1]], dp[i-1][j]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }


    cout << dp[n][x];

    

    return 0;
}