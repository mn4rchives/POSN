#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n"

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s1, s2;
    cin>>s1>>s2;

    vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));

    int r=0, c=0;
    for(char c1:s1){
        r+=1;
        c=0;
        for(char c2:s2){
            c+=1;
            if(c1==c2){
                dp[r][c] = dp[r-1][c-1]+1;
            }else dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
        }
    }

    cout << dp[r][c];

    return 0;  
}