#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 9e18;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> co(n + 1);
    vector<int> dp(n + 1, INF);

    for (int i = 1; i <= n; i++) {
        cin >> co[i];
    }

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {

        dp[i] = min(dp[i],
                    dp[i - 1] + abs(co[i] - co[i - 1]));

        if (i > 2) {
            dp[i] = min(dp[i],
                        dp[i - 2] + abs(co[i] - co[i - 2]));
        }
    }

    cout << dp[n];

    return 0;
}