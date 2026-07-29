#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
int n;
vector<int>ind, v1, v2;

bool check(int mid){
    int lo=0, hi=mid;
    for(int i=0; i<n; i++){
        int x;
        int num = ind[i]-(v2[i]*mid);

        if(v1[i]-v2[i]==0){
            if(num<0) return false;
        }else if(v1[i]>v2[i]){
            x = num/(v1[i]-v2[i]);
            hi = min(hi, x);

        }else if(v2[i]>v1[i]){
            x = ceil((float)num/(float)(v1[i]-v2[i]));
            lo = max(lo, x);
        }
        if(lo>hi) return false;
    }
    return lo<=hi;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;

    ind.resize(n);
    v1.resize(n);
    v2.resize(n);

    for(int i=0; i<n; i++){
        cin>>ind[i];
    }
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    for(int i=0; i<n; i++){
        cin>>v2[i];
    }
    int lo=0, hi=1e9, ans=hi;
    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(check(mid)){
            lo = mid+1;
            ans = mid;
        }else{
            hi = mid-1;
        }
    }

    cout << ans;


    return 0;  
}