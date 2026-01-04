/*************************
  Author: Defy logic guy
  14:53:31 - 13/12/2025
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
#define int unsigned long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "OLPSV2025_MARBLES"

struct node
{
    int i, j, x, y;
    node(int i = 0, int j = 0, int x = 0, int y = 0) : i(i), j(j), x(x), y(y) {}
};

struct hsh
{
    size_t operator()(pair<int, int> const &p) const { return (size_t)(p.first ^ (p.second << 1)); }
};

int n, m, p;
vector<int> rnd(m + 1, 0), rnd1(m + 1, 0);
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
void pre()
{
    for (int i = 1; i <= m; i++)
    {
        while (!rnd[i])
            rnd[i] = rng();
        while (!rnd1[i])
            rnd1[i] = rng();
    }
}

void solve()
{
    cin >> n >> m >> p;
    vector<vector<node>> v(m + 1);
    for (int _ = 0; _ < p; _++)
    {
        int i, j, x, y, c;
        cin >> i >> j >> x >> y >> c;
        v[c].pb(node(i, j, x, y));
    }

    pre();

    vector<vector<int>> h(n + 1, vector<int>(n + 1, 0)), h1(n + 1, vector<int>(n + 1, 0));
    for (int _ = 1; _ <= m; _++)
    {
        if (v[_].empty())
            continue;
        vector<vector<int>> d(n + 2, vector<int>(n + 2, 0));
        for (auto it : v[_])
        {
            auto [i, j, x, y] = it;
            d[i][j]++;
            d[i][y + 1]--;
            d[x + 1][j]--;
            d[x + 1][y + 1]++;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                h[i][j] += rnd[_] * d[i][j];
                h1[i][j] += rnd1[_] * d[i][j];
            }
    }

    unordered_map<pair<int, int>, int, hsh> mp;
    mp.reserve((size_t)n * n * 2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mp[make_pair(h[i][j], h1[i][j])]++;

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << mp[make_pair(h[u][v], h1[u][v])] << '\n';
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
