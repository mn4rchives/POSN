#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, W;
    cin>>N>>W;

    vector<int>w(N), v(N);

    for(int i=0; i<N; i++){
        cin>>w[i]>>v[i];
    }

    vector<vector<int>>dp(N+1, vector<int>(W+1, 0));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            if(j-w[i-1]<0){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j], (dp[i-1][j-w[i-1]])+v[i-1]);
            }
        }
    }

    cout << dp[N][W];

    return 0;  
}