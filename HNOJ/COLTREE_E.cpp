/*************************
  Author: Defy logic guy
  20:02:31 - 27/02/2026
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
#define NAME "COLTREE_E"

void solve()
{
    int n;
    cin >> n;
    set<int> c[n + 1];
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        c[i].insert(x);
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> ans(n + 1);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        for (int v : adj[u])
            if (v != p)
            {
                dfs(v, u);
                if (c[u].size() < c[v].size())
                    swap(c[u], c[v]);
                for (int i : c[v])
                    c[u].insert(i);
            }
        ans[u] = c[u].size();
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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
