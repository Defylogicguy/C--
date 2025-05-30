/*************************
  Author: Defy logic guy
  22:30:37 - 24/05/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "KHOANGCACHTRONGCAY"

int n, k;
int ans = 0;
vector<vector<int>> dp, tree;

void dfs(int u, int p)
{
    dp[u][0] = 1;
    for (int v : tree[u])
    {
        if (v == p)
            continue;
        dfs(v, u);

        for (int i = 0; i < k; i++)
            if (k - i - 1 >= 0 and k - i - 1 < dp[v].size())
                ans += dp[u][i] * dp[v][k - i - 1];

        for (int i = 1; i <= k; i++)
            dp[u][i] += dp[v][i - 1];
    }
}

void solve()
{
    cin >> n >> k;
    tree.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(1, 0);
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
