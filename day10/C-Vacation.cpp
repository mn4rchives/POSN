#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<int>a(n), b(n), c(n);
    vector<vector<int>>dp(3, vector<int>(n+1, 0));

    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    dp[0][1]=a[0];
    dp[1][1]=b[0];
    dp[2][1]=c[0];

    int ma=0, mb=0, mc=0;
    for(int i=2; i<=n; i++){
        ma = max({dp[1][i-1], dp[2][i-1]});
        mb = max({dp[0][i-1], dp[2][i-1]});
        mc = max({dp[0][i-1], dp[1][i-1]});

        dp[0][i]=ma+a[i-1];
        dp[1][i]=mb+b[i-1];
        dp[2][i]=mc+c[i-1];
    }

    cout << max({dp[0][n], dp[1][n], dp[2][n]});

    return 0;
}