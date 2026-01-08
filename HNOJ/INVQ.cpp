/*************************
  Author: Defy logic guy
  20:22:56 - 08/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "INVQ"

int s;
const int maxn = 1e5 + 7;
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
vector<int> f(maxn, 0);
void upd(int idx, int val)
{
    while (idx < maxn)
    {
        f[idx] += val;
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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<Query> qry(q);
    for (int i = 0; i < q; i++)
        cin >> qry[i].l >> qry[i].r, qry[i].l--, qry[i].r--, qry[i].idx = i;
    s = sqrt(n);
    sort(all(qry));
    vector<int> res(q);
    int cl = 0, cr = -1, ans = 0;
    for (int i = 0; i < q; i++)
    {
        int l = qry[i].l, r = qry[i].r;
        auto addl = [&](int i)
        {
            ans += get(a[i] - 1);
            upd(a[i], 1);
        };
        auto rml = [&](int i)
        {
            upd(a[i], -1);
            ans -= get(a[i] - 1);
        };
        auto addr = [&](int i)
        {
            ans += get(n) - get(a[i]);
            upd(a[i], 1);
        };
        auto rmr = [&](int i)
        {
            upd(a[i], -1);
            ans -= get(n) - get(a[i]);
        };
        while (cl > l)
            addl(--cl);
        while (cr < r)
            addr(++cr);
        while (cl < l)
            rml(cl++);
        while (cr > r)
            rmr(cr--);
        res[qry[i].idx] = ans;
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << endl;
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
