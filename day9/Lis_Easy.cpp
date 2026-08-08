#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    vector<int>v(n), dp(n, 0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    dp[n-1]=0;

    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(v[i]>=v[j]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
    }

    cout << *max_element(dp.begin(), dp.end())+1;

    return 0;  
}