/*************************
  Author: Defy logic guy
  23:50:41 - 03/01/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 2004010501
#define endl '\n'
#define NAME "Skibidi"

int n, m, k;
int one(int i){ return i > n ? one(i - n) : i; }
int two(int i) { return i > m ? two(i - m) : i; }

void solve()
{
    cin >> n >> m >> k;

    vector<vector<bool>> a(n + 1, vector<bool>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == '.');
        }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[one(2 * i + 1)][two(2 * j - 1)] && a[one(2 * i)][two(2 * j - 1)])
                if (i + 1 <= n)
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;

            if (a[one(2 * i - 1)][two(2 * j + 1)] && a[one(2 * i - 1)][two(2 * j)])
                if (j + 1 <= m)
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
        }

    cout << dp[n][m] << endl;
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