/*************************
  Author: Defy logic guy
  10:49:18 - 14/06/2025
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
#define NAME "COWPALIN"

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<vector<int>> prv(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        prv[i][i] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; j++)
        {
            if ((n - 1 - j - i) < 0)
                continue;
            for (int k = 0; k < n; k++)
            {
                if ((n - 1 - k + i) >= n)
                    continue;
                if (a[j][(n - 1 - j - i)] != a[k][(n - 1 - k + i)])
                    continue;
                dp[j][k] = prv[j][k];
                if (j + 1 < n)
                    dp[j][k] += prv[j + 1][k];
                if (k - 1 >= 0)
                    dp[j][k] += prv[j][k - 1];
                if (j + 1 < n and k - 1 >= 0)
                    dp[j][k] += prv[j + 1][k - 1];
                dp[j][k] %= MOD;
            }
        }
        prv = dp;
    }
    cout << prv[0][n - 1] << endl;
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
