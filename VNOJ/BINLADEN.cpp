/*************************
  Author: Defy logic guy
  20:08:52 - 21/07/2026
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
#define NAME "BINLADEN"

void solve()
{
    int n, m;
    cin >> n >> m;
    auto f = [&](int f, int r)
    { return f * m + r; };
    int t = (n + 1) * m;
    vector<vector<pair<int, int>>> adj(t);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int w;
            cin >> w;
            int u = f(i - 1, j), v = f(i, j);
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        for (int j = 0; j < m - 1; j++)
        {
            int w;
            cin >> w;
            int u = f(i, j), v = f(i, j + 1);
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
    }
    vector<int> d(t, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int j = 0; j < m; j++)
    {
        d[f(0, j)] = 0;
        pq.push({0, f(0, j)});
    }
    while (pq.size())
    {
        auto [dd, u] = pq.top();
        pq.pop();
        if (dd != d[u])
            continue;
        for (auto [v, w] : adj[u])
            if (d[v] > dd + w)
            {
                d[v] = dd + w;
                pq.push({d[v], v});
            }
    }
    cout << d[f(n, m - 1)] << '\n';
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
