#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
int n;
vector<int>ind, v1, v2;

bool check(int mid){
    for(int i=0; i<n; i++){

    }
    return true;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

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
    int lo=0, hi=2e9, ans=hi;
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

// x*v1 + (mid-x) *v2 <= ind;