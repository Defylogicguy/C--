/*************************
  Author: Defy logic guy
  10:26:16 - 19/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CATTREE"

vector<int> a;
vector<vector<int>> adj;
int n, m;

int dfs(int u, int p, int cnt)
{
    cnt = (a[u] ? cnt + 1: 0);

    if (cnt > m)
        return 0;

    bool flag = true;
    int res = 0;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        flag = false;
        res += dfs(v, u, cnt);
    }

    if (flag)
        return 1;
    return res;
}

void solve()
{
    cin >> n >> m;
    a.resize(n + 1);
    adj.assign(n + 1, {});

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cout << dfs(1, 0, 0) << endl;
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
