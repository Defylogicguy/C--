/*************************
  Author: Defy logic guy
  21:10:55 - 18/02/2025
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
#define NAME "D281"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pf(n, 0);
    pf[0] = a[0];
    for (int i = 1; i < n; i++)
        pf[i] = pf[i - 1] + a[i];

    vector<int> _max(n);
    _max[0] = pf[0];
    for (int i = 1; i < n; i++)
        _max[i] = max(_max[i - 1], pf[i]);

    int cur = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, cur + _max[i]);
        cur += pf[i];
    }
    cout << ans << endl;
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
