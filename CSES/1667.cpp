/*************************
  Author: Defy logic guy
  21:04:27 - 17/07/2026
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
#define NAME "1667"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    vector<int> d(n + 1, 0), par(n + 1, 0);
    d[1] = 1, par[1] = 0;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!d[v])
            {
                d[v] = d[u] + 1;
                par[v] = u;
                q.push(v);
            }
    }
    if (d[n] == 0)
        cout << "IMPOSSIBLE";
    else
    {
        cout << d[n] << '\n';
        vector<int> path;
        int cur = n;
        while (cur != 0)
            path.pb(cur), cur = par[cur];
        reverse(all(path));
        for (int i : path)
            cout << i << ' ';
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
