/*************************
  Author: Defy logic guy
  22:25:35 - 02/09/2025
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
#define NAME "607B"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(n, LLONG_MAX));
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }
            if (i + 1 == j)
            {
                dp[i][j] = a[i] == a[j] ? 1 : 2;
                continue;
            }
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            if (a[i] == a[j])
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
        }
    cout << dp[0][n - 1] << '\n';
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
