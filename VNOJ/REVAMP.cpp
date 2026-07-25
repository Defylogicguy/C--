/*************************
  Author: Defy logic guy
  21:40:11 - 21/07/2026
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
#define NAME "REVAMP"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vector<vector<int>> d(n + 1, vector<int>(k + 1, LLONG_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    d[1][0] = 0;
    pq.push({0, 1, 0});
    while (pq.size())
    {
        auto [l, u, ud] = pq.top();
        pq.pop();
        if (l > d[u][ud])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (d[v][ud] > l + w)
            {
                d[v][ud] = l + w;
                pq.push({d[v][ud], v, ud});
            }
            if (ud < k and d[v][ud + 1] > l)
            {
                d[v][ud + 1] = l;
                pq.push({d[v][ud + 1], v, ud + 1});
            }
        }
    }
    int ans = LLONG_MAX;
    for (int j = 0; j <= k; j++)
        ans = min(ans, d[n][j]);
    cout << ans;
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
