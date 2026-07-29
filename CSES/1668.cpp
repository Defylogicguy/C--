/*************************
  Author: Defy logic guy
  20:18:54 - 14/07/2026
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
#define NAME "1668"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    bool flag = true;
    vector<bool> vis(n + 1, false);
    vector<int> team(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        function<bool(int, int)> dfs = [&](int u, int ct)
        {
            vis[u] = true;
            team[u] = ct;
            for (int v : adj[u])
            {
                if (!team[v])
                {
                    bool t = dfs(v, 3 - ct);
                    if (!t)
                        return false;
                }
                else if (team[v] == ct)
                    return false;
            }
            return true;
        };
        bool idk = dfs(i, 1);
        if (!idk)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
        cout << "IMPOSSIBLE";
    else
        for (int i = 1; i <= n; i++)
            cout << team[i] << ' ';
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
