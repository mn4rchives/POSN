#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    int ans=0;

    while(n>0){
        int x=n;
        int m=0;
        while(x){
            int y=x%10;
            x/=10;
            m = max(m, y);
        }
        n-=m;
        ans++;
    }

    cout << ans;

    return 0;
}