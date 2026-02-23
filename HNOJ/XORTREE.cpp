/*************************
 Author: Defy logic guy
19:38:11 - 14/02/2026
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
#define NAME "XORTREE"

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<int> pf(n + 1, -1);
    function<void(int)> dfs = [&](int u)
    {
        for (auto [v, w] : adj[u])
            if (pf[v] == -1)
            {
                pf[v] = (pf[u] ^ w);
                dfs(v);
            }
    };
    pf[1] = 0;
    dfs(1);
    int ans = 0;
    for (int i = 20; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = 2; j <= n; j++)
            if ((pf[j] >> i) & 1)
                cnt++;
        ans += (1 << (i + 1)) * cnt * (n - cnt);
    }
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
