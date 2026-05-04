#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<pair<int, int>> co;
vector<tuple<double, int, int>> vt;
vector<int> parent, sz;

void create(){
    parent.resize(n);
    sz.assign(n, 1);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
}

int find(int u){
    if(parent[u]==u) return u;
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a, b);
    parent[b] = a;
    sz[a]+=sz[b];
    return true;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n>>k;
    int num=n*(n-1)/2;
    co.resize(n);
    vt.resize(num);

    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        co[i]={a,b};
    }

    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double dx = co[i].first - co[j].first;
            double dy = co[i].second - co[j].second;
            double sum = dx*dx + dy*dy;
            vt[count++]={sum, i, j};
        }
    }

    sort(vt.begin(), vt.end());

    create();

    int edges_used = 0;
    double ans = 0;

    for(auto& [w, u, v] : vt){
        if(unite(u, v)){
            edges_used++;
            ans = w;
            if(edges_used == n - k) break;
        }
    }

    cout<<ans;

    return 0;
}