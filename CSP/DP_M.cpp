/*************************
  Author: Defy logic guy
  14:20:53 - 16/08/2025
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
#define NAME "DP_M"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(k + 1, 0), dpn(k + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> pf(k + 1, 0);
        pf[0] = dp[0];
        for (int j = 1; j <= k; j++)
            pf[j] = (pf[j - 1] + dp[j]) % MOD;
        for (int j = 0; j <= k; j++)
        {
            dpn[j] = pf[j];
            if (j - a[i] >= 1)
                dpn[j] = (dpn[j] - pf[j - a[i] - 1] + MOD) % MOD;
        }
        dp = dpn;
    }

    cout << dp[k];
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
