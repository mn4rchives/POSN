#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"
vector<vector<int>>vv;
vector<int>dis;

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    vv.resize(n+1);
    dis.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        vv[a].push_back(b);
        vv[b].push_back(a);
    }
    int ans=0;
    queue<int>q;
    for(auto x:vv[1]){
        q.push(x);
        dis[x]=1;
        ans++;
    }
    dis[1]=1;
    debug(ans);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto y:vv[x]){
            if(dis[y]==1) continue;
            dis[y]=1;
            debug(y);
            ans++;
        }
    }

    cout << ans;



    return 0;  
}