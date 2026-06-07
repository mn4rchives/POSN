#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
const int MOD=1e9+7;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;
    vector<string>v(n);
    dp.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) cin>>v[i];

    dp[0][0]=1;

    if(v[0][0]=='*' or v[n-1][n-1]=='*'){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 and j==0) continue;
            if(v[i][j]=='*') continue;
            
            if(i-1<0){
                dp[i][j]=(dp[i][j-1])%MOD;
            }else if(j-1<0){
                dp[i][j]=(dp[i-1][j])%MOD;
            }else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout << dp[n-1][n-1];
    return 0;  
}