/*************************
  Author: Defy logic guy
  08:45:50 - 07/06/2025
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
#define endl '\n'
#define NAME "DEFKINGDOM"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edg;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edg.pb({u, v});
    }

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int cnt = 0;
    vector<int> x(n + 1, 0);
    for (auto &[u, v] : edg)
        if (c[u] != c[v])
            x[u]++, x[v]++, cnt++;

    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (x[i] == cnt)
            ans.pb(i);
    cout << (ans.size() ? "YES\n" : "NO\n");
    for (int i : ans)
        cout << i << ' ';
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
