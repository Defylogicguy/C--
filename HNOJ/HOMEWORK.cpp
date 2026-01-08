/*************************
  Author: Defy logic guy
  09:26:33 - 14/06/2025
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
#define MOD 1000000007
#define NAME "HOMEWORK"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> t(n + 1), a(m + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e18));
    dp[1][1] = a[t[1]];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, k); j++)
            dp[i][j] = dp[i - 1][j - 1] + (t[i] == t[i - 1] ? b[t[i]] : a[t[i]]);
        for (int j = max(i - k - 1, 0ll); j < i - 1; j++)
            dp[i][1] = min(dp[i][1], dp[i - 1][i - j - 1] + (t[i] == t[j] ? b[t[i]] : a[t[i]]));
    }
    cout << *min_element(dp[n].begin() + 1, dp[n].begin() + k + 1) << endl;
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
