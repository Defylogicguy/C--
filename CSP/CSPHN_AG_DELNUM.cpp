/*************************
  Author: Defy logic guy
  15:29:54 - 22/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_AG_DELNUM"

vector<int> spf;

void sieve()
{
    spf.assign(1e6 + 1, 0);
    iota(all(spf), 0);
    for (int i = 2; i <= 1e6; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= 1e6; j += i)
                if (spf[j] == j)
                    spf[j] = i; 
}

void solve()
{
    sieve();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n, 0), pre(1e6 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x > 1)
        {
            int p = spf[x];
            dp[i] = max(dp[i], pre[p] + 1);
            while (x % p == 0)
                x /= p;
        }

        x = a[i];
        while (x > 1)
        {
            int p = spf[x];
            pre[p] = max(pre[p], dp[i]);
            while (x % p == 0)
                x /= p;
        }
    }
    cout << n - *max_element(all(dp)) << endl;
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
