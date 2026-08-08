#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";
const int INF=4e18;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    vector<int>dp(n+1, INF);

    dp[0]=0;

    for(int i=1; i<=n; i++){
        int x=i;
        while(x){
            int y=x%10;
            x/=10;
            dp[i] = min(dp[i], dp[i-y]+1);
        }
    }

    cout << dp[n];

    return 0;
}