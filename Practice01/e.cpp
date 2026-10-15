#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
int n, t;
vector<int>cow;

bool check(int k){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<n; i++){
        if(i<k) {
            if(cow[i]>t) return false;
            pq.push(cow[i]);
            continue;
        }
        int x=pq.top()+cow[i];
        pq.pop();
        if(x>t) return false;
        pq.push(x);
    }
    return true;

}


int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    // freopen("cowdance.in", "r",stdin);
    // freopen("cowdance.out", "w",stdout);

    cin>>n>>t;

    cow.resize(n);

    for(int i=0; i<n; i++){
        cin>>cow[i];
    }

    int lo=1, hi=t+10, ans=hi;
    int mid=(lo+hi)/2;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(check(mid)){
            hi = mid-1;
            ans = mid;
        }else{
            lo = mid+1;
        }
        // debug(mid);
    }

    cout<<ans;

    return 0;  
}