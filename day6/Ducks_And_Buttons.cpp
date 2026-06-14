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


    int po = max_element(v.begin(), v.end())-v.begin();
    int ans=0, id=0;
    while(po<n){
        ans+=((po-id)*v[po]);
        id=po;
        po = max_element(v.begin()+id+1, v.end())-v.begin();

    }
    cout << ans;





    return 0;
}