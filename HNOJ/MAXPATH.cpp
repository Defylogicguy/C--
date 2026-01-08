/*************************
  Author: Defy logic guy
  08:24:40 - 02/06/2025
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
#define NAME "MAXPATH"

vector<vector<int>> adj;
vector<int> a;
int max_sum = LLONG_MIN;

int dfs(int u, int p, int &res)
{
    int one = 0, two = 0;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        int val = dfs(v, u, res);
        if (val > one)
        {
            two = one;
            one = val;
        }
        else if (val > two)
            two = val;
    }

    res = max(res, a[u] + one + two);
    return max(0LL, a[u] + one);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int res = LLONG_MIN;
    dfs(1, 0, res);
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
