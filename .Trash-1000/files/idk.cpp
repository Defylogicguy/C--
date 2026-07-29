/*************************
  Author: Defy logic guy
  21:55:23 - 28/07/2026
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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v),adj[v].pb(u);
    }
    auto bfs = [&](int x)
    {
        vector<int> d(n + 1, -1);
        queue<int> q;
        q.push(x);
        d[x] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
                if (d[v] == -1)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
        }
        int t = x;
        for (int i = 1; i <= n; i++)
            if (d[i] > d[t])
                t = i;
        return make_pair(t, d);
    };
    auto [a, _] = bfs(1);
    auto [b, da] = bfs(a);
    auto [__, db] = bfs(b);
    for (int i = 1; i <= n; i++)
        cout << max(da[b], max(da[i], db[i]) + 1) << '\n';
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
