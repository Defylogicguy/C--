/*************************
  Author: Defy logic guy
  14:31:36 - 09/08/2025
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
#define NAME "SAM3"

void solve()
{
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> ans(n + 1, 0), dp1(n + 1, 0), dp2(n + 1, 0), dp3(n + 1, 0), a(n + 1, 0), b(n + 1), c(n + 1);
    ans[0] = 1;
    dp1[0] = dp2[0] = dp3[0] = 0;
    a[0] = b[0] = c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int t = a[i - 1];
        if ((i - p - 1) >= 0)
            t -= a[i - p - 1];
        t %= MOD;
        if (t < 0)
            t += MOD;
        dp1[i] = t;
        t = b[i - 1];
        if ((i - q - 1) >= 0)
            t -= b[i - q - 1];
        t %= MOD;
        if (t < 0)
            t += MOD;
        dp2[i] = t;
        t = c[i - 1];
        if ((i - r - 1) >= 0)
            t -= c[i - r - 1];
        t %= MOD;
        if (t < 0)
            t += MOD;
        dp3[i] = t;
        ans[i] = (dp1[i] + dp2[i] + dp3[i]) % MOD;
        a[i] = (a[i - 1] + (ans[i] - dp1[i]) % MOD) % MOD;
        if (a[i] < 0)
            a[i] += MOD;
        b[i] = (b[i - 1] + (ans[i] - dp2[i]) % MOD) % MOD;
        if (b[i] < 0)
            b[i] += MOD;
        c[i] = (c[i - 1] + (ans[i] - dp3[i]) % MOD) % MOD;
        if (c[i] < 0)
            c[i] += MOD;
    }
    cout << ans[n] ;
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
