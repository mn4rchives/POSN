#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
vector<int>vis;
vector<vector<int>>vv;
vector<int>cs;

void bfs(int i){
    queue<int>q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int b:vv[a]){
            if(vis[b]) continue;
            if(cs[b]) continue;
            vis[b] = 1;
            q.push(b); 
        }
    }
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    freopen("closing.in", "r",stdin);
    freopen("closing.out", "w",stdout);
    int n, m;
    cin>>n>>m;
    vis.assign(n+1, 0);
    vv.resize(n+1);
    cs.assign(n+1, 0);



    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        vv[a].push_back(b); 
        vv[b].push_back(a); 
    }


    for(int j=0; j<n; j++){
        int cmp=0 ;
        vis.assign(n+1, 0);
        for(int i=1; i<=n; i++){
            if(vis[i]) continue;
            if(cs[i]) continue;
            bfs(i);
            cmp+=1;
        }
        // debug(cmp);
        if(cmp==1){
             cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        int x; cin>>x;
        cs[x] = 1;
    }



    return 0;
}