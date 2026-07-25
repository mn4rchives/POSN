#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    int ans=0;
    cin>>n>>k;
    
    vector<pair<int, int>>mon(n);
    vector<int>bo(k);
    vector<int>ch(k, 0);

    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        mon[i] = {a, b};
    }

    for(int i=0; i<k; i++){
        cin>>bo[i];
    }

    sort(mon.begin(), mon.end());
    sort(bo.begin(), bo.end());

    for(int i=0; i<n; i++){
        int num=0;
        int pob = -1;
        auto point = upper_bound(bo.begin(), bo.end(), mon[i].first);
        if(point == bo.end()){
            num = min(abs(bo[k-1]-mon[i].first), mon[i].second);
            if(num==abs(bo[k-1]-mon[i].first) and num != mon[i].second) pob = k-1;
            ans+=num;
        }else if(point == bo.begin()){
            num = min(abs(bo[0]-mon[i].first), mon[i].second);
            if(num==abs(bo[0]-mon[i].first) and num != mon[i].second) pob = 0;
            ans+=num;
        }else{
            int po1 = point-bo.begin(), po2 = point-bo.begin()-1;
            num = min({abs(bo[po1]-mon[i].first), abs(bo[po2]-mon[i].first), mon[i].second});
            if(num==abs(bo[po1]-mon[i].first)and num != mon[i].second) pob = po1;
            if(num==abs(bo[po2]-mon[i].first)and num != mon[i].second) pob = po2;
            if(num==abs(bo[po2]-mon[i].first) and num==abs(bo[po1]-mon[i].first)){
                if(ch[po2]==1){
                    pob = po2;
                }else{
                    pob = po1;
                }
            }
            ans+=num;
        }
 
        if(pob != -1){
            ch[pob] = 1;
        }
        
    }
    int count=0;
    for(int i=0; i<k; i++){
        count += ch[i];
    }
    cout << ans+count;

    return 0;  
}