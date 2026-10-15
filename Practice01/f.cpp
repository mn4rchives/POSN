#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num; cin>>num;
    for(int i=0; i<num; i++){
        int n; cin>>n;

        vector<int>v(n+1);
        v[n] = 0;
        for(int j=0; j<n; j++) cin>>v[j];
        
        int per=1;
        int ans=0;
        for(int j=0; j<n; j++){
            if(per==1){
                if(v[j]==0){
                    if(v[j+1]==0){
                        if(v[j+2]==0){
                            per = 2;
                            continue;
                        }
                        j++;
                        per = 2;
                    }else{
                        per = 2;
                        continue;
                    }

                }else{
                    if(v[j+1]==0){
                        if(v[j+2]==0){
                            per = 2;
                            continue;
                        }
                        ans++;
                        j++;
                        per = 2;
                    }else{
                        ans++;
                        per = 2;
                        continue;
                    }
                }
        //person 1

            }else{
                if(v[j]==0){
                    if(v[j+1]==0){
                        per = 1;
                        continue;
                    }else{
                        per = 1;
                        j++;
                    }

                }else{
                    if(v[j+1]==0){
                        per = 1;
                        continue;
                    }else{
                        per = 1;
                        j++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;  
}