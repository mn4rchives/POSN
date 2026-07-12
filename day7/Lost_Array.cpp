#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x;
const int INF = 1e9;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    vector<int>v(n, INF);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(v[a-1]<c or v[a-1]==INF) v[a-1]=c;
        if(v[b-1]<c or v[b-1]==INF) v[b-1]=c;
    }

    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    return 0;
}