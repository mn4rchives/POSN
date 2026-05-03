#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;

    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1; i<n+1; i++){
        if(i-2<0){ 
            dp[i] = dp[i-1];
            continue;
        }
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout << dp[n];

    return 0;  
}