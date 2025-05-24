/*************************
  Author: Defy logic guy
  09:56:52 - 24/05/2025
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
#define NAME "DPTREE_SONCHUONG"

vector<vector<int>> dp, tree;
vector<int> col;
void dfs(int u, int p)
{
    for (int i = 0; i < 3; i++)
        dp[u][i] = 1;

    if (col[u] != 0)
        for (int i = 0; i < 3; i++)
            if (i != col[u] - 1)
                dp[u][i] = 0;
    for (int v : tree[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        vector<int> tmp(3, 0);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    tmp[i] = (tmp[i] + dp[u][i] * dp[v][j]) % MOD;
        dp[u] = tmp;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    tree.resize(n + 1), col.resize(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    for (int i = 1; i <= k; i++)
    {
        int b, c;
        cin >> b >> c;
        col[b] = c;
    }
    dp.assign(n + 1, vector<int>(3, 0));
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD << endl;
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
