/*************************
  Author: Defy logic guy
  11:37:42 - 18/07/2025
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
#define NAME "DPDIGIT_INCREASING"

int cnt(string s)
{
    int n = s.size();
    int dp[n + 1][2][10];
    memset(dp, 0, sizeof(dp));

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++)
        for (int t = 0; t < 2; t++)
            for (int j = 0; j < 10; j++)
            {
                if (dp[i][t][j] == 0)
                    continue;
                int l = t ? (s[i] - '0') : 9;
                for (int d = j; d <= l; d++)
                    dp[i + 1][t && (d == l)][d] = (dp[i + 1][t && (d == l)][d] + dp[i][t][j]) % MOD;
            }

    int res = 0;
    for (int t = 0; t < 2; t++)
        for (int i = 0; i < 10; i++)
            res += dp[n][t][i];

    return res;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (--a[i] < '0')
            a[i] = '9';
        else
            break;
    }
    if (a[0] == '0')
        a.erase(a.begin());
    int ans = cnt(b) - cnt(a) + MOD;
    cout << ans % MOD;
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
