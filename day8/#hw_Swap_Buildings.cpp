#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio();

    int n; cin>>n;
    map<int, int>cnt;

    for(int i=0; i<n; i++){
        int x;cin>>x;
        cnt[x]++;
    }

    int ans=0;

    for(auto [key, freq]: cnt){
        // debug(freq);
        if(freq==0) continue;
        ans += (n-freq)*freq;
    }

    cout << ans/2;

    return 0;
}

