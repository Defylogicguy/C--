/*************************
  Author: Defy logic guy
  15:07:31 - 11/06/2026
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
#define NAME "idk"

struct BIT
{
    int n, m;
    vector<vector<int>> a;
    BIT(int n = 0, int m = 0) : n(n), m(m) { a.assign(n + 1, vector<int>(m + 1, 0)); };
    void upd(int idx1, int idx2, int x)
    {
        for (int i = idx1; i <= n; i += i & -i)
            for (int j = idx2; j <= m; j += j & -j)
                a[i][j] += x;
    }
    int f(int idx1, int idx2)
    {
        int ans = 0;
        for (int i = idx1; i > 0; i -= i & -i)
            for (int j = idx2; j > 0; j -= j & -j)
                ans += a[i][j];
        return ans;
    }
    int get(int x1, int y1, int x2, int y2) { return f(x2, y2) - f(x1 - 1, y2) - f(x2, y1 - 1) + f(x1 - 1, y1 - 1); }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    BIT fen(n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1, x; j <= m; j++)
        {
            cin >> x;
            fen.upd(i, j, x);
        }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y, val;
            cin >> x >> y >> val;
            fen.upd(x, y, val);
        }
        else if (t == 2)
        {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            cout << fen.get(x, y, u, v) << '\n';
        }
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
