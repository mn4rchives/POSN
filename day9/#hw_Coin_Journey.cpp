#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >>n>>q;

    vector<int> r(n);
    vector<int> mx(n);

    int sum=0;

    for(int i=0; i<n; i++){
        cin>>r[i];

        sum+=r[i];

        if(i==0)
            mx[i]=sum;
        else
            mx[i]=max(mx[i-1], sum);
    }

    for(int i=0; i<q; i++){
        int c;
        cin>>c;

        auto it=lower_bound(mx.begin(), mx.end(), c);

        if(it==mx.end())
            cout<<-1;
        else
            cout<<it-mx.begin()+1;

        if(i!=q-1)
            cout <<" ";
    }

    return 0;
}