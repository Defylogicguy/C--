/*************************
  Author: Defy logic guy
  19:55:24 - 24/07/2026
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
#define NAME "GRAPH_"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> num(n + 1, -1), low(n + 1);
    vector<bool> j(n + 1, false);
    int cur = 1, one = 0, two = 0;
    function<void(int, int)> dfs = [&](int u, int p)
    {
        num[u] = low[u] = cur++;
        int cnt = 0;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            if (num[v] == -1)
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] == num[v])
                    two++;
                cnt++;
                if (p == 0)
                {
                    if (cnt > 1)
                        j[u] = true;
                }
                else if (low[v] >= num[u])
                    j[u] = true;
            }
            else
                low[u] = min(low[u], num[v]);
        }
    };
    for (int i = 1; i <= n; i++)
        if (num[i] == -1)
            dfs(i, 0);
    for (int i = 1; i <= n; i++)
        one += j[i];
    cout << one << ' ' << two;
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
