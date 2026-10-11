#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

vector<vector<int>>vis;
vector<string>v;
vector<int>dr = {1, 0, -1, 0};
vector<int>dc = {0, -1, 0, 1};

int n;
int mx_area = 0, area = 0;
int p = 0, mn_p = 4e9;

void bfs(int r, int c){
    queue<pair<int, int>>q;
    q.push({r, c});
    vis[r][c] = 1;

    area = 0;
    p = 0;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        area++;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 or nr >= n or nc < 0 or nc >= n){
                p++;
                continue;
            }

            if(v[nr][nc] == '.'){
                p++;
                continue;
            }

            if(vis[nr][nc]) continue;

            vis[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("perimeter.in", "r",stdin);
    freopen("perimeter.out", "w",stdout);

    cin >> n;

    vis.assign(n, vector<int>(n, 0));
    v.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] == '.') continue;
            if(vis[i][j]) continue;

            bfs(i, j);

            if(area > mx_area or
               (area == mx_area and p < mn_p)){
                mx_area = area;
                mn_p = p;
            }
        }
    }

    cout << mx_area << " " << mn_p;

    return 0;
}