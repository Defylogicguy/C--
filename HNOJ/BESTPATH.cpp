/*************************
  Author: Defy logic guy
  09:30:21 - 07/06/2025
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
#define NAME "BESTPATH"

int res = LLONG_MIN;
int dfs(int u, int p, const vector<vector<int>> &adj, const vector<int> &s)
{
    int one = 0, two = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        int x = dfs(v, u, adj, s);
        if (x > one)
        {
            two = one;
            one = x;
        }
        else if (x > two)
            two = x;
    }
    res = max(res, s[u] + max(0ll, one) + max(0ll, two));
    return s[u] + max(0ll, one);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1, adj, a);
    cout << res << endl;
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
