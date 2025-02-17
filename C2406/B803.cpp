/*************************
  Author: Defy logic guy
  20:08:10 - 15/02/2025
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
#define NAME "B803"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    vector<int> c(m + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i< m; i++)
        cin >> b[i];
    for (int i = 0; i <= m; i++)
        cin >> c[i];

    map<string, int> mp;
    for (int i = 0; i < m; i++)
        mp[b[i]] = c[i + 1];

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (mp[a[i]] == 0)
            ans += c[0];
        else
            ans += mp[a[i]];

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
