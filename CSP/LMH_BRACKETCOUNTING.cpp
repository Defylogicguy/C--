/*************************
  Author: Defy logic guy
  14:33:42 - 23/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 123456789
#define NAME "LMH_BRACKETCOUNTING"

void solve()
{
    int n, k;
    cin >> n >> k;
    n >>= 1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= k; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            for (int k = 1; k <= i; k++)
                dp[i][j] = (dp[i][j] + (dp[i - k][j] * dp[k - 1][j - 1]) % MOD) % MOD;
    cout << (dp[n][k] - dp[n][k - 1] + MOD) % MOD;
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
