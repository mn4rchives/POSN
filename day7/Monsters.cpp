#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    int ans=0;
    cin>>n>>k;

    vector<pair<int, int>>vp(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        vp[i]={a, b};
    }
    vector<int>b(k);
    for(int i=0; i<k; i++){
        cin>>b[i];
    }

    sort(b.begin(), b.end());
    sort(vp.begin(), vp.end());
    int count=0;
    bool bo=true;
    int po=0;
    for(int i=0; i<n; i++){
        if(vp[i].first>b[po]){
            if(abs(vp[i].first-b[po+1])<abs(vp[i].first-b[po]) and po+1<k){
                po++;
                bo=true;
            }
        }
        int x = min(abs(vp[i].first-b[po]), vp[i].second);
        if(x==abs(vp[i].first-b[po]) and bo){
            count++;
            bo=false;
        }
        ans+=x;
    }

    cout << ans+count;

    return 0;  
}