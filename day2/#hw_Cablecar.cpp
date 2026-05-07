#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<pair<int,int>>> g;

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    g.resize(n+1);

    for(int i=0;i<m;i++){

        int a,b,c;
        cin >> a >> b >> c;

        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    int s,d,p;
    cin >> s >> d >> p;

    vector<int> cap(n+1,0);

    priority_queue<pair<int,int>> pq;

    cap[s] = 1e18;

    pq.push({cap[s],s});

    while(!pq.empty()){

        auto [cur,v] = pq.top();
        pq.pop();

        if(cur < cap[v]) continue;

        for(auto [u,w] : g[v]){

            int newCap = min(cur,w);

            if(newCap > cap[u]){

                cap[u] = newCap;

                pq.push({newCap,u});
            }
        }
    }

    int pe = cap[d] - 1;

    int ans;

    if(p % pe == 0)
        ans = p / pe;
    else
        ans = p / pe + 1;

    cout << ans;

    return 0;
}