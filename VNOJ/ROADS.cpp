/*************************
  Author: Defy logic guy
  19:39:11 - 25/07/2026
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
#define NAME "ROADS"

struct node
{
    int v, l, c;
    node(int v = 0, int l = 0, int c = 0) : v(v), l(l), c(c) {}
    const bool operator<(const node &o) const { return l > o.l; }
};

void solve()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<node>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        adj[u].pb(node(v, l, c));
    }
    vector<vector<int>> d(n + 1, vector<int>(k + 1, INT_MAX));
    d[1][k] = 0;
    heap<node> q;
    q.push(node(1, 0, k));
    while (q.size())
    {
        int u = q.top().v, ll = q.top().l, cc = q.top().c;
        q.pop();
        if (ll > d[u][cc])
            continue;
        if (u == n)
        {
            cout << ll << '\n';
            return;
        }
        for (node it : adj[u])
        {
            int v = it.v, w = it.l, c = it.c;
            if (cc >= c and d[v][cc - c] > ll + w)
            {
                d[v][cc - c] = ll + w;
                q.push(node(v, d[v][cc - c], cc - c));
            }
        }
    }
    cout << -1 << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
