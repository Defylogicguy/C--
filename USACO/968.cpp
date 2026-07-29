/*************************
  Author: Defy logic guy
  20:07:06 - 28/07/2026
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
#define NAME "milkvisits"

void solve()
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = " " + s;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> id(n + 1, 0);
    int cur = 0;
    auto dfs = [&](auto &&self, int u) -> void
    {
        for (int v : adj[u])
            if (!id[v] and s[v] == s[u])
            {
                id[v] = cur;
                self(self, v);
            }
    };
    for (int i = 1; i <= n; i++)
        if (!id[i])
        {
            id[i] = ++cur;
            dfs(dfs, i);
        }
    while (q--)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (id[u] == id[v])
            cout << (s[u] == c);
        else
            cout << 1;
    }
}

signed main()
{
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
