/*************************
  Author: Defy logic guy
  20:34:54 - 01/08/2025
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
#define NAME "PINV"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1), ndp(k + 1), pf(k + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pf[0] = dp[0];
        for (int j = 1; j <= k; j++)
            pf[j] = (pf[j - 1] + dp[j]) % MOD;
        for (int j = 0; j <= k; j++)
            ndp[j] = (pf[j] - (j - i + 1 > 0 ? pf[j - i] : 0) + MOD) % MOD;
        swap(dp, ndp);
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
