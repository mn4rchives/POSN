#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;
    vector<double>p(n);

    for(int i=0; i<n; i++){
        cin>>p[i];
    }

    vector<vector<double>>dp(n+1, vector<double>(n+1, 0));
    dp[0][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(j==0){
                dp[i][j] = (dp[i-1][j]*(1-(p[i-1])));
            }else dp[i][j] = (dp[i-1][j]*(1-(p[i-1]))) + (dp[i-1][j-1]*(p[i-1]));
        }
    }

    double ans=0;
    for(int i=n/2+1; i<=n; i++){
        ans+=dp[n][i];
    }

    cout << fixed << setprecision(10) << ans;

    return 0;  
}