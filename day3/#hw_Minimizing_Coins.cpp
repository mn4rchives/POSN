#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=4e18;
vector<int>v, dp;
int n, x;

int find_min(int num){
    int ans=INF;
    for(int i=0; i<n; i++){
        if(num-v[i]<0) continue;
        if(dp[num-v[i]]==-1) continue;
        ans=min(ans, dp[num-v[i]]+1);
    }
    if(ans==INF) return -1;
    return ans;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin>>n>>x;

    v.resize(n);
    dp.assign(x+1, -1);
    dp[0]=0;

    for(int i=0; i<n; i++) cin>>v[i];

    for(int i=1; i<=x; i++){
        dp[i]=find_min(i);
        // cout << dp[i] << "\n";
    }

    cout << dp[x];






    return 0;
}