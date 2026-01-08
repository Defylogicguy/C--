/*************************
  Author: Defy logic guy
  13:25:41 - 10/06/2025
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
#define NAME "DUCKCOUNTRY"

void dfs(int u, int p, int d, int &far, int &mx, const vector<vector<pair<int, int>>> &adj)
{
    if (d > mx)
        mx = d, far = u;
    for (auto &[v, w] : adj[u])
        if (p != v)
            dfs(v, u, d + w, far, mx, adj);
}

void dfs1(int u, int p, vector<int> &vec, int &end, const vector<vector<pair<int, int>>> &adj)
{
    if (u == end)
        return;
    for (auto &[v, w] : adj[u])
        if (v != p)
        {
            vec[v] = vec[u] + w;
            dfs1(v, u, vec, end, adj);
        }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    int mx = -1, far = -1;
    dfs(1, -1, 0, far, mx, adj);
    int a = far;
    mx = -1;
    dfs(far, -1, 0, far, mx, adj);
    int b = far;

    vector<int> mxa(n + 1, LLONG_MAX), mxb(n + 1, LLONG_MAX);
    mxa[a] = 0, mxb[b] = 0;

    dfs1(a, -1, mxa, b, adj);
    dfs1(b, -1, mxb, a, adj);

    for (int i = 1; i <= n; i++)
        cout << max(mxa[i], mxb[i]) << ' ';
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
