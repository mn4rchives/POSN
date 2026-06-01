#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v1(n), v2(n);

    for(int i = 0; i < n; i++) cin >> v1[i];
    for(int i = 0; i < n; i++) cin >> v2[i];

    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = v1[0];
    dp[0][1] = v2[0];

    for(int i = 1; i < n; i++) {
        dp[i][0] = max(
            dp[i-1][0] + v1[i],
            dp[i-1][1] + v1[i] - k
        );

        dp[i][1] = max(
            dp[i-1][1] + v2[i],
            dp[i-1][0] + v2[i] - k
        );
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
}