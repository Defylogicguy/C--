/*************************
  Author: Defy logic guy
  23:40:15 - 16/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
{
    for (auto it = c.begin(); it != c.end(); ++it)
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
#define NAME "2063C"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
        deg[u]++, deg[v]++;
    }

    if (n <= 2)
    {
        cout << 0 << '\n';
        return;
    }

    vector<unordered_set<int>> v(n + 1);
    for (int u = 1; u <= n; u++)
        for (int j : adj[u])
            v[u].insert(j);

    vector<int> o(n);
    iota(all(o), 1);
    sort(all(o), [&](int a, int b)
         { return deg[a] > deg[b]; });

    int mx = 0;
    for (int u = 1; u <= n; u++)
        for (int j : o)
        {
            if (j == u)
                continue;
            if (v[u].find(j) == v[u].end())
            {
                mx = max(mx, deg[u] + deg[j] - 1);
                break;
            }
        }

    int mxx = 0;
    for (int u = 1; u <= n; u++)
        for (int j : adj[u])
            if (u < j)
                mxx = max(mxx, deg[u] + deg[j] - 2);

    cout << max(mx, mxx) << "\n";
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
    cout.tie(nullptr);

    int tt = 1;
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
