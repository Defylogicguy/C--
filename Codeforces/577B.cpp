/*************************
  Author: Defy logic guy
  10:40:50 - 04/09/2025
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
#define NAME "577B"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n > m)
    {
        cout << "YES\n";
        return;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][a[i] % m] = true;
        if (!i)
            continue;
        for (int j = 0; j < m; j++)
        {
            dp[i][(a[i] + j) % m] = dp[i][(a[i] + j) % m] | dp[i - 1][j];
            dp[i][j] = dp[i][j] | dp[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
            cerr << dp[i][j] << " \n"[j == m - 1];
    cout << (dp[n - 1][0] ? "YES\n" : "NO\n");
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
