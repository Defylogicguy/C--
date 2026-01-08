/*************************
  Author: Defy logic guy
  08:56:47 - 24/05/2025
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
#define NAME "DPTREE_MAXBRANCH"

void dfs(const vector<int> &a, const vector<vector<int>> &tree, vector<vector<int>> &dp, int u)
{
    dp[u][0] = 0;
    dp[u][1] = a[u];

    for (int v : tree[u])
    {
        dfs(a, tree, dp, v);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> tree(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        if (u != 0)
            tree[u].pb(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dfs(a, tree, dp, 1);

    cout << max(dp[1][0], dp[1][1]) << endl;
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
