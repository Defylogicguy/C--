/*************************
  Author: Defy logic guy
  21:39:13 - 25/07/2026
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
#define NAME "NETACCEL"

struct node
{
    double d;
    int u, used;
    node(double d = 0, int u = 0, int used = 0) : d(d), u(u), used(used) {}
    bool operator<(const node &other) const { return d > other.d; }
};

const double INF = 1e100;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, double>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        double c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    vector<vector<double>> d(n + 1, vector<double>(k + 1, INF));
    priority_queue<node> pq;
    d[1][0] = 0;
    pq.push(node(0, 1, 0));
    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();
        int use = t.used;
        if (t.d != d[t.u][use])
            continue;
        for (auto [v, w] : adj[t.u])
        {
            if (d[v][t.used] > t.d + w)
            {
                d[v][t.used] = t.d + w;
                pq.push({d[v][t.used], v, t.used});
            }
            double c = w;
            for (int add = 1; t.used + add <= k; add++)
            {
                c /= 2.0;
                if (d[v][t.used + add] > t.d + c)
                {
                    d[v][t.used + add] = t.d + c;
                    pq.push({d[v][t.used + add], v, t.used + add});
                }
            }
        }
    }
    double ans = INF;
    for (int i = 0; i <= k; i++)
        ans = min(ans, d[n][i]);
    cout << fixed << setprecision(2) << ans << '\n';
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
