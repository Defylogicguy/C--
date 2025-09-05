/*************************
  Author: Defy logic guy
  19:17:55 - 05/09/2025
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
#define NAME "TRUNGBINHCONG"

int add(int x, int y)
{
    if (y < 0)
        y += MOD;
    (x += y) %= MOD;
    return x;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> pfa(n + 1, 0), pfb(n + 1, 0);
    for (int i = 0; i < n; cin >> a[i++], pfa[i] = add(pfa[i - 1], a[i - 1]))
        ;
    for (int i = 0; i < n; cin >> b[i++], pfb[i] = add(pfb[i - 1], b[i - 1]))
        ;
    vector<vector<int>> c;
    for (int i = 0; i < n; i++)
    {
        c.resize(i + 1);
        iota(all(c[i]), 0);
        sort(all(c[i]), [&](int x, int y)
             { return (pfb[i + 1] - pfb[x]) * (i - y) < (pfb[i + 1] - pfb[y]) * (i - x); });
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> d(i + 1);
        iota(all(d), 0);
        sort(all(d), [&](int x, int y)
             { return (pfa[i + 1] - pfa[x]) * (i - y) < (pfa[i + 1] - pfa[y]) * (i - x); });
        
    }
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
