/*************************
  Author: Defy logic guy
  20:00:21 - 18/07/2025
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
#define NAME "DPDIGIT_DACBIET"

vector<int> v[1459], x(20);
vector<vector<int>> dp(20, vector<int>(1459, -1));
bitset<1459> vis;
void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (auto x : v[u])
        dfs(x);
}

int f(int i, int t, int sum)
{
    if (i < 0)
        return !vis[sum];
    if (t and dp[i][sum] != -1)
        return dp[i][sum];
    int l = t ? 9 : x[i];
    int ans = 0;
    for (int j = 0; j <= l; j++)
        ans += f(i - 1, t || (j < l), sum + j * j);
    if (t)
        return dp[i][sum] = ans;
    return ans;
}

int cnt(int xx)
{
    int n = 0;
    x[0] = 0;
    for (; xx > 0; n++)
    {
        x[n] = xx % 10;
        xx /= 10;
    }
    return f(n - 1, 0, 0);
}

void solve()
{
    for (int i = 1; i < 1459; i++)
    {
        int x = i;
        int sum = 0;
        while (x)
        {
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        v[sum].pb(i);
    }
    dfs(1);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << cnt(r) - cnt(l - 1) << '\n';
    }
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
