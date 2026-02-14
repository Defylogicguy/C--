/*************************
  Author: Defy logic guy
  19:57:48 - 12/02/2026
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
#define NAME "LUBENICA"

struct node
{
    int x, a, b;
    node(int x = -1, int a = LLONG_MAX, int b = 0) : x(x), a(a), b(b) {}
};

void solve()
{
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    vector<vector<node>> up(n + 1, vector<node>(20));
    vector<int> h(n + 1, -1);

    queue<int> q;
    h[1] = 0;
    q.push(1);

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u])
        {
            if (h[v] == -1)
            {
                h[v] = h[u] + 1;
                up[v][0] = node(u, w, w);
                q.push(v);
            }
        }
    }
    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
            if (up[i][j - 1].x != -1)
            {
                up[i][j].x = up[up[i][j - 1].x][j - 1].x;
                up[i][j].a = min(up[i][j - 1].a, up[up[i][j - 1].x][j - 1].a);
                up[i][j].b = max(up[i][j - 1].b, up[up[i][j - 1].x][j - 1].b);
            }

    int qq;
    cin >> qq;

    while (qq--)
    {
        int u, v;
        cin >> u >> v;

        int mn = LLONG_MAX;
        int mx = 0;

        if (h[u] < h[v])
            swap(u, v);

        int k = h[u] - h[v];
        for (int i = 0; i < 20; i++)
            if ((k >> i) & 1)
                mn = min(mn, up[u][i].a), mx = max(mx, up[u][i].b), u = up[u][i].x;

        if (u == v)
        {
            cout << mn << ' ' << mx << '\n';
            continue;
        }

        for (int i = 19; i >= 0; i--)
            if (up[u][i].x != -1 && up[u][i].x != up[v][i].x)
            {
                mn = min(mn, min(up[u][i].a, up[v][i].a)), mx = max(mx, max(up[u][i].b, up[v][i].b));
                u = up[u][i].x, v = up[v][i].x;
            }

        mn = min(mn, min(up[u][0].a, up[v][0].a));
        mx = max(mx, max(up[u][0].b, up[v][0].b));

        cout << mn << ' ' << mx << '\n';
    }
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
