/*************************
  Author: Defy logic guy
  22:55:37 - 21/02/2026
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
#define NAME "XORLR"

int s;
struct Query
{
    int l, r, idx;
    Query(int l = 0, int r = 0, int idx = 0) : l(l), r(r), idx(idx) {}
    bool operator<(const Query &o) const
    {
        int ba = l / s;
        int bb = o.l / s;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (r > o.r) : (r < o.r);
    }
};

void solve()
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1, [](const int &a, const int &b)
                { return a ^ b; });
    vector<int> c = pf;
    for (int i = 0; i <= n; i++)
        c.pb(pf[i] ^ k);
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    vector<int> id(n + 1), id2(n + 1);
    for (int i = 0; i <= n; i++)
        id[i] = lower_bound(all(c), pf[i]) - c.begin(),
        id2[i] = lower_bound(all(c), pf[i] ^ k) - c.begin();
    vector<int> mp(c.size(), 0);
    vector<Query> qry(q);
    for (int i = 0; i < q; i++)
        cin >> qry[i].l >> qry[i].r, qry[i].idx = i, qry[i].l--;
    s = sqrt(n);
    sort(all(qry));
    int res = 0;
    auto add = [&](int i)
    {
        res += mp[id2[i]];
        mp[id[i]]++;
    };
    auto rm = [&](int i)
    {
        mp[id[i]]--;
        res -= mp[id2[i]];
    };
    vector<int> ans(q);
    int cl = 0, cr = -1;
    for (int i = 0; i < q; i++)
    {
        int l = qry[i].l, r = qry[i].r;
        while (cr < r)
            add(++cr);
        while (cr > r)
            rm(cr--);
        while (cl < l)
            rm(cl++);
        while (cl > l)
            add(--cl);
        ans[qry[i].idx] = res;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
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
