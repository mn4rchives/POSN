#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<'\n'

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, d;
    cin>>n>>d;

    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    int ans=0;
    int m=0;
    for(int i=n-1; i>0; i--){
        m = max(m, v[i]);
        ans+=m;
    }

    cout << ans;





    return 0;
}