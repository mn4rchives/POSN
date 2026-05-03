#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int>parent, sz;
vector<int>hp;

void create(){
    parent.resize(n+1);
    sz.assign(n+1, 1);
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }
}

int find(int u){
    if(parent[u]==u) return u;
    return parent[u] = find(parent[u]);
}

int unite(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a==b) return -1;
    if(hp[a]<hp[b]) swap(a,b);
    if(hp[a]==hp[b]){
        if(b<a) swap(a,b);
    }
    // cout << "a=" << hp[a] << "b=" << hp[b] << "\n";
    parent[b] = a; 
    hp[a]+=hp[b]/2;
    return a;
}

bool same(int u, int v){
    return find(u)==find(v);
}


int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n>>m;
    hp.resize(n+1);
    for(int i=1; i<=n; i++){
        int a; cin>>a;
        hp[i] = a;
    }

    create();

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        cout << unite(a, b) << "\n";


    }
    

    return 0;  
}