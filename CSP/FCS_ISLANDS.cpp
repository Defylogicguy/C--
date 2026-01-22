/*************************
  Author: Defy logic guy
  16:54:42 - 17/01/2026
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
#define NAME "ISLANDS"

struct DSU
{
    DSU(int n = 0) { init(n); }
    vector<int> par, sz;
    void init(int n)
    {
        par.resize(n + 1);
        iota(all(par), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }
    int size(int x) { return sz[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    void uni(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        par[y] = x;
        sz[x] += sz[y];
    }
};

int dx[4] = {0, 0, 1, -1},
    dy[4] = {1, -1, 0, 0};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b.emplace_back(a[i][j], i * m + j);
        }
    sort(all(b), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first > b.first; });
    DSU dsu(m * n);
    vector<bool> state(m * n, false);
    int cnt = 0, ans = 0;
    int i = 0;
    while (i < b.size())
    {
        int j = i;
        while (j < b.size() and b[j].first == b[i].first)
        {
            state[b[j].second] = true;
            cnt++;

            int x = b[j].second / m, y = b[j].second % m;

            for (int _ = 0; _ < 4; _++)
            {
                int nx = x + dx[_], ny = y + dy[_];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m)
                    continue;
                if (state[nx * m + ny] and !dsu.same(nx * m + ny, b[j].second))
                {
                    cnt--;
                    dsu.uni(nx * m + ny, b[j].second);
                }
            }
            j++;
        }
        ans = max(ans, cnt);
        i = j;
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
