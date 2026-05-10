#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dp;
const int mod=1e9+7;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    dp.assign(n+1, 0);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=6; j++){
            if(i-j<0) break;
            cnt+=dp[i-j];
        }
        dp[i]=cnt % mod;
    }
    
    cout << dp[n];


    return 0;  
}