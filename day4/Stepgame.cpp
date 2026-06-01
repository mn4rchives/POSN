#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=4e18;
vector<int>dp;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;
    int ans=INF;
    dp.resize(n+1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int num;
        cin>>num;

        if(dp[i-1]+num<num){
            dp[i]=dp[i-1]+num;
        }else{
            dp[i]=num;
        }
        ans = min(ans, dp[i]);

    }

    cout << ans;

    return 0;
}