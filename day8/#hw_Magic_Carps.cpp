#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr<<#x<<"="<<x<<"\n";

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<long long> J(n), E(n);
    for (int i=0; i<n; i++) cin>>J[i];
    for (int i=0; i<n; i++) cin>>E[i];

    int ans = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                int score =
                    J[i] * (E[j] + E[k]) +
                    J[j] * (E[i] + E[k]) +
                    J[k] * (E[i] + E[j]);
                ans = max(ans, score);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}