/*************************
  Author: Defy logic guy
  20:28:30 - 18/07/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "idk"

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INT_MAX)), nxt(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
        d[i][i] = 0, nxt[i][i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < d[u][v])
        {
            d[u][v] = d[v][u] = w;
            nxt[u][v] = v, nxt[v][u] = u;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (d[i][k] != INT_MAX)
                for (int j = 1; j <= n; j++)
                    if (d[k][j] != INT_MAX)
                        if (d[i][j] > d[i][k] + d[k][j])
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]), nxt[i][j] = nxt[i][k];
    while (q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            cout << (d[u][v] == INT_MAX ? -1 : d[u][v]) << '\n';
        else
        {
            if (nxt[u][v] == -1)
            {
                cout << "-1\n";
                continue;
            }
            vector<int> path;
            int cur = u;
            while (cur != v)
                path.pb(cur), cur = nxt[cur][v];
            path.pb(v);
            cout << path.size() << ' ';
            for (int x : path)
                cout << x << ' ';
            cout << '\n';
        }
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
