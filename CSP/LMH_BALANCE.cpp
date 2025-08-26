/*************************
  Author: Defy logic guy
  15:05:40 - 23/08/2025
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
#define NAME "LMH_BALANCE"

void solve()
{
    int n,m;
    cin >> n >> m;
    int s = n * (n + 1) / 2;
    if (m > s)
    {
        cout << 0;
        return;
    }
    int sz = 2 * s + 1;
    vector<int> dp(sz, 0);
    dp[s] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> ndp(sz, 0);
        for (int j = 0; j < sz; j++)
        {
            if (dp[j] == 0)
                continue;
            int x = dp[j];
            (ndp[j] += x) %= MOD;
            if (j + i < sz)
                (ndp[j + i] += x) %= MOD;
            if (j - i >= 0)
            (ndp[j - i] += x) %= MOD;
        }
        dp = ndp;
    }
    cout << dp[s + m] % MOD << '\n';
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "i", stdout);
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
