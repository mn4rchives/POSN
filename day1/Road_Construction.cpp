#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans2=1;
int ans1;
vector<int>parent, sz;

void built(){
    parent.resize(n+1);
    sz.assign(n+1, 1);
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int fd(int u){
    if(parent[u]==u) return u;
    return parent[u]=fd(parent[u]);
}

void unite(int u, int v){
    int a = fd(u);
    int b = fd(v);
    if(a==b) return;
    ans1-=1;
    if(sz[a]<sz[b]) swap(a, b);
    // cout << "a=" << sz[a] << ' ' << "b=" << sz[b] << " ";
    parent[b] = a;
    sz[a]=sz[a]+sz[b];
    ans2=max(sz[a], ans2);
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin>>n;
    ans1=n;
    int num; cin>>num;
    built();
    for(int i=0; i<num; i++){
        int a, b; cin>>a>>b;
        unite(a, b);
        
        cout << ans1 << " ";
        cout << ans2 << "\n";

    }


    return 0;
}