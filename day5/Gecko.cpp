#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dx={-1, 0, 1};

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w;
    cin>>h>>w;

    vector<vector<int>>vv(h, vector<int>(w));
    vector<vector<int>>dp(h, vector<int>(w, 0));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>vv[i][j];
    }

    for(int i=0; i<w; i++) dp[0][i]=vv[0][i];

    for(int i=1; i<h; i++){
        for(int j=0; j<w; j++){
            if(j-1<0){
                dp[i][j]=max(dp[i-1][j], dp[i-1][j+1])+vv[i][j];
            }else if(j+1==w){
                dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+vv[i][j];
            }else dp[i][j]=max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]})+vv[i][j];
        }
    }

    int ans=0;
    ans = *max_element(dp[h-1].begin(), dp[h-1].end());

    cout << ans;

    return 0;  
}