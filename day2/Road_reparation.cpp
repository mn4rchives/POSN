#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<tuple<int, int, int>>vt;
vector<int>parent, sz;
int n, m;

void create(){
    parent.resize(n+1);
    sz.assign(n+1, 1);
    for(int i=1; i<n+1; i++){
        parent[i]=i;
    }
}

int find(int v){
    if(parent[v]==v) return v;
    return parent[v]=find(parent[v]);
}

void unite(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a, b);
    parent[b]=a;
    sz[a]+=sz[b];
}

bool same(int u, int v){
    if(find(u)==find(v)) return true;
    return false;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        vt.push_back({c, a, b});
    }

    sort(vt.begin(), vt.end());

    int dis=0, count=0;
    bool ch=false;

    create();
    for(auto& [w, u, v] : vt){
        if(same(u, v)) continue;
        unite(u, v);
        dis+=w;
        count++;
        if(count==n-1){
            cout << dis;
            ch=true;
            break;
        }
    }

    if(!ch) cout << "IMPOSSIBLE";

    


    return 0;  
}