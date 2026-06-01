#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dp;

int memo(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]) return dp[n];
    return dp[n] = memo(n-1)+memo(n-2);
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;

    dp.assign(n+1, 0);
    memo(n);

    cout << dp[n];

    return 0;  
}