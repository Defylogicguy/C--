/*************************
  Author: Defy logic guy
  14:07:38 - 01/11/2025
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
    for (auto it = c.begin(); it != c.end(); ++it)
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
#define NAME "CSPHN_QHD_TOWER"

struct item
{
    int a, b, h;
};

const int maxn = 1000005;
static int tree[maxn];
// static int comp[2 * maxn];
static item a[maxn];

inline void upd(int idx, int val)
{
    for (; idx < maxn; idx += idx & -idx)
        tree[idx] = max(tree[idx], val);
}

inline int query(int idx)
{
    int res = 0;
    for (; idx > 0; idx -= idx & -idx)
        res = max(res, tree[idx]);
    return res;
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sz = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].h;
        // comp[sz++] = a[i].a;
        // comp[sz++] = a[i].b;
    }

    // sort(comp, comp + sz);
    // sz = unique(comp, comp + sz) - comp;

    // auto get = [&](int x)
    // {
    //     return (int)(lower_bound(comp, comp + sz, x) - comp) + 1;
    // };

    sort(a, a + n, [](const item &x, const item &y)
         { return x.b == y.b ? x.a > y.a : x.b < y.b; });

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // int A = get();
        // int B = get();
        int cur = query(a[i].a) + a[i].h;
        upd(a[i].b, cur);
        ans = max(ans, cur);
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
