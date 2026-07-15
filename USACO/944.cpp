/*************************
  Author: Defy logic guy
  20:18:30 - 07/07/2026
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
#define NAME "fenceplan"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> check(n + 1, false);
    int ans = LLONG_MAX;
    for (int i = 1; i <= n; i++)
        if (!check[i])
        {
            int mxx = a[i].first, mxy = a[i].second, mnx = mxx, mny = mxy;
            function<void(int)> dfs = [&](int u)
            {
                mxx = max(mxx, a[u].first), mnx = min(mnx, a[u].first),
                mxy = max(mxy, a[u].second), mny = min(mny, a[u].second);
                check[u] = true;
                for (int v : adj[u])
                    if (!check[v])
                        dfs(v);
            };
            dfs(i);
            ans = min(ans, mxx - mnx + mxy - mny);
        }
    cout << ans * 2;
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
