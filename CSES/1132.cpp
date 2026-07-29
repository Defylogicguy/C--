/*************************
  Author: Defy logic guy
  20:59:09 - 28/07/2026
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
#define NAME "1132"

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
    auto dfs = [&](auto &&self, int u, int p) -> pair<int, int>
    {
        pair<int, int> res = {0, u};
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            auto t = self(self, v, u);
            t.first++;
            if (t.first > res.first)
                res = t;
        }
        return res;
    };
    auto p1 = dfs(dfs, 1, 0);
    int a = p1.second;
    auto p2 = dfs(dfs, a, 0);
    int d = p2.first, b = p2.second;
    vector<int> da(n + 1, INT_MAX), db(n + 1, INT_MAX);
    queue<int> q;
    q.push(a);
    da[a] = db[b] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (da[v] == INT_MAX)
            {
                da[v] = da[u] + 1;
                q.push(v);
            }
    }
    q.push(b);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (db[v] == INT_MAX)
            {
                db[v] = db[u] + 1;
                q.push(v);
            }
    }
    for (int i = 1; i <= n; i++)
        cout << max(da[i], db[i]) << ' ';
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
