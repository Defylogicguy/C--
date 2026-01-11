/*************************
  Author: Defy logic guy
  22:45:02 - 08/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "ABCXYZZ"

int s;
struct Query
{
    int l, r, a, b, idx;
    Query(int l = 0, int r = 0, int a = 0, int b = 0, int idx = 0) : l(l), r(r), a(a), b(b), idx(idx) {}
    bool operator<(const Query &other) const
    {
        int ba = l / s;
        int bb = other.l / s;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (r > other.r) : (r < other.r);
    }
};
const int maxn = 1e5 + 7;
struct Fenwick
{
    int f[maxn];
    Fenwick() {}
    void upd(int idx, int x)
    {
        while (idx < maxn)
        {
            f[idx] += x;
            idx += idx & -idx;
        }
    }
    int get(int idx)
    {
        int res = 0;
        while (idx)
        {
            res += f[idx];
            idx -= idx & -idx;
        }
        return res;
    }
} f[2];
int cnt[maxn];
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<Query> qry(q);
    for (int i = 0; i < q; i++)
        cin >> qry[i].l >> qry[i].r >> qry[i].a >> qry[i].b, qry[i].l--, qry[i].r--, qry[i].idx = i;
    s = 475;
    sort(all(qry));
    int cl = 0, cr = -1;
    auto add = [&](int i)
    {
        int val = v[i];
        f[0].upd(val, 1);
        cnt[val]++;
        if (cnt[val] == 1)
            f[1].upd(val, 1);
    };
    auto del = [&](int i)
    {
        int val = v[i];
        f[0].upd(val, -1);
        cnt[val]--;
        if (cnt[val] == 0)
            f[1].upd(val, -1);
    };
    vector<pair<int, int>> res(q);
    for (int i = 0; i < q; i++)
    {
        int l = qry[i].l, r = qry[i].r, a = qry[i].a, b = qry[i].b, idx = qry[i].idx;
        while (cr < r)
            add(++cr);
        while (cr > r)
            del(cr--);
        while (cl < l)
            del(cl++);
        while (cl > l)
            add(--cl);
        res[idx] = make_pair(f[0].get(b) - f[0].get(a - 1), f[1].get(b) - f[1].get(a - 1));
    }
    for (int i = 0; i < q; i++)
        cout << res[i].first << ' ' << res[i].second << '\n';
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
