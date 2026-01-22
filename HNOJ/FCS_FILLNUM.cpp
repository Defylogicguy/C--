/*************************
  Author: Defy logic guy
  22:48:51 - 16/01/2026
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
// #define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "FILLNUM"

struct Queries
{
    int l, r, k;
    Queries(int l = 0, int r = 0, int k = 0) : l(l), r(r), k(k) {}
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<Queries> qry(m);
    for (int i = 0; i < m; i++)
        cin >> qry[i].l >> qry[i].r >> qry[i].k;

    vector<int> d(n + 1, 0), par(n + 2, 0);
    iota(all(par), 0);

    function<int(int)> find = [&](int x) -> int
    { return par[x] = (par[x] == x ? x : find(par[x])); };

    for (int i = m - 1; i >= 0; i--)
    {
        auto &[l, r, kk] = qry[i];
        int p = find(l);
        while (p <= r)
        {
            d[p] = kk;
            par[p] = p + 1;
            p = find(p);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = ((ans * 10) % k + d[i]) % k;
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
