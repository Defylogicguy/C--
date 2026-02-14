/*************************
  Author: Defy logic guy
  22:12:51 - 12/02/2026
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
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "GGLCA"

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

    vector<vector<int>> up(n + 1, vector<int>(18, -1));
    vector<int> d(n + 1, -1);
    d[1] = 0;
    queue<int> qq;
    qq.push(1);
    while (qq.size())
    {
        int x = qq.front();
        qq.pop();
        for (int v : adj[x])
            if (d[v] == -1)
            {
                d[v] = d[x] + 1;
                qq.push(v);
                up[v][0] = x;
            }
    }

    for (int j = 1; j < 18; j++)
        for (int i = 1; i <= n; i++)
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];

    int q;
    cin >> q;
    while (q--)
    {
        int u, v, r;
        cin >> u >> v >> r;
        auto lca = [&](int a, int b) -> int
        {
            if (d[a] < d[b])
                swap(a, b);
            int k = d[a] - d[b];
            for (int i = 17; i >= 0; i--)
                if ((k >> i) & 1)
                    a = up[a][i];
            if (a == b)
                return a;
            for (int i = 17; i >= 0; i--)
                if (up[a][i] != -1 and up[a][i] != up[b][i])
                    a = up[a][i], b = up[b][i];
            return up[a][0];
        };
        int ans = lca(u, v), y = lca(u, r), z = lca(v, r);
        if (d[y] > d[ans])
            ans = y;
        if (d[z] > d[ans])
            ans = z;
        cout << ans << '\n';
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
