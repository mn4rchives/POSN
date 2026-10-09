#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x;

int32_t main(){
    freopen("bcount.in", "r",stdin);
    freopen("bcount.out", "w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin>>n>>q;
    vector<int>v(n);
    vector<int>dp1(n+1), dp2(n+1), dp3(n+1);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    dp1[0] = 0;
    dp2[0] = 0;
    dp3[0] = 0;

    for(int i=0; i<n; i++){
        if(v[i]==1){
             dp1[i+1]=dp1[i]+1;
             dp2[i+1]=dp2[i];
             dp3[i+1]=dp3[i];
        }else if(v[i]==2){
             dp2[i+1]=dp2[i]+1;
             dp1[i+1]=dp1[i];
             dp3[i+1]=dp3[i];
        }else{
             dp3[i+1]=dp3[i]+1;
             dp1[i+1]=dp1[i];
             dp2[i+1]=dp2[i];
        }
    }

    for(int i=0; i<q; i++){
        int a, b; cin>>a>>b;
        cout << dp1[b]-dp1[a-1] << " ";
        cout << dp2[b]-dp2[a-1] << " ";
        cout << dp3[b]-dp3[a-1] << "\n";
    }


    return 0;
}