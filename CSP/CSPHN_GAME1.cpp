/*************************
  Author: Defy logic guy
  15:49:00 - 09/08/2025
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
#define NAME "CSPHN_GAME1"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];

    vector<int> pfa(n + 1, 0), pfb(m + 1, 0);
    for (int i = 0; i < n; i++)
        pfa[i + 1] = pfa[i] + a[i + 1] - 1;
    for (int j = 0; j < m; j++)
        pfb[j + 1] = pfb[j] + b[j + 1] - 1;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, LLONG_MAX));
    dp[0][0] = 0;
    vector<int> c(m + 1, LLONG_MAX);
    for (int i = 1; i <= n; i++)
    {
        int mn = LLONG_MAX;
        for (int j = 1; j <= m; j++)
        {
            if (dp[i - 1][j - 1] < LLONG_MAX)
            {
                mn = min(mn, dp[i - 1][j - 1] - (a[i] - 1) * pfb[j - 1]);
                c[j] = min(c[j], dp[i - 1][j - 1] - (b[j] - 1) * pfa[i - 1]);
            }
            int one = LLONG_MAX, two = LLONG_MAX;
            if (mn < LLONG_MAX)
                one = mn + (a[i] - 1) * pfb[j];
            if (c[j] < LLONG_MAX)
                two = c[j] + (b[j] - 1) * pfa[i];
            dp[i][j] = min(one, two);
        }
    }
    cout << dp[n][m];
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
