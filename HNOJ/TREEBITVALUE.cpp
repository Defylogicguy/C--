/*************************
  Author: Defy logic guy
  10:30:02 - 07/06/2025
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
#define NAME "TREEBITVALUE"

void dfs(int u, int p, int d, int &far, int &mx, const vector<vector<int>> &adj, const set<int> &s)
{
    if (d > mx and s.count(u))
        mx = d, far = u;
    for (int v : adj[u])
        if (p != v)
            dfs(v, u, d + 1, far, mx, adj, s);
}

int dia(const vector<int> &a, const vector<vector<int>> &adj)
{
    if (a.size() <= 1)
        return 0;

    set<int> s(all(a));
    int mx = -1, far = -1;
    dfs(a[0], -1, 0, far, mx, adj, s);
    mx = -1;
    dfs(far, -1, 0, far, mx, adj, s);
    return mx;
}

void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[__builtin_popcountll(x)].pb(i);
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 0;
    for (auto &[_, x] : mp)
        ans = max(ans, dia(x, adj));

    cout << ans;
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
