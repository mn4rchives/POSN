#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int c, r;
    cin>>c>>r;
    int x=25;

    vector<vector<int>>dp(x, vector<int>(x, 0));
    dp[0][0]=1;

    for(int i=1; i<x; i++){
        for(int j=0; j<=i+1; j++){
            if(j-1<0){
                dp[i][j]=dp[i-1][j];
            }else if(j==i){
                dp[i][j]=dp[i-1][j-1];
            }else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }

    cout << dp[c-1][r-1];

    return 0;  
}