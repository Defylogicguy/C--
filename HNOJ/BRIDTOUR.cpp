/*************************
  Author: Defy logic guy
  20:27:11 - 24/07/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "BRIDTOUR"

const int maxn = 2e5 + 5;
int up[maxn][19], h[maxn], t[maxn];

int lca(int a, int b)
{
    if (h[a] != h[b])
    {
        if (h[a] < h[b])
            swap(a, b);
        int k = h[a] - h[b];
        for (int i = 18; i >= 0; i--)
            if (k >> i & 1)
                a = up[a][i];
    }
    if (a == b)
        return a;
    for (int i = 18; i >= 0; i--)
        if (up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    return up[a][0];
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    h[1] = 1;
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    for (int j = 1; j <= 18; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        t[u]++, t[v]++;
        t[lca(u, v)] -= 2;
    }
    int ans = 0;
    auto dfs2 = [&](auto &&self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            t[u] += t[v];
            if (!t[v])
                ans++;
        }
    };
    dfs2(dfs2, 1, 0);
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
