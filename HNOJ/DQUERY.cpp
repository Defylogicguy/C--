/*************************
  Author: Defy logic guy
  20:12:35 - 08/08/2025
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
#define NAME "DQUERY"
int s;
struct Query
{
    int l, r, idx;
    Query(int l = 0, int r = 0, int idx = 0) : l(l), r(r), idx(idx) {}
    bool operator<(const Query &other) const
    {
        int ba = l / s;
        int bb = other.l / s;
        if (ba != bb)
            return ba < bb;
        return (ba & 1) ? (r > other.r) : (r < other.r);
    }
};

const int maxn = 1e6 + 7;
vector<int> cnt(maxn);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;
    vector<Query> qry(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qry[i].l >> qry[i].r;
        qry[i].l--, qry[i].r--;
        qry[i].idx = i;
    }

    s = sqrt(n);
    sort(all(qry));

    vector<int> res(q);
    int cl = 0, cr = -1;
    int cur = 0;

    auto add = [&](int i)
    {
        int val = a[i];
        cnt[val]++;
        if (cnt[val] == 1)
            cur++;
    };

    auto rm = [&](int i)
    {
        int val = a[i];
        cnt[val]--;
        if (cnt[val] == 0)
            cur--;
    };

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
        res[qry[i].idx] = cur;
    }

    for (int i = 0; i < q; i++)
        cout << res[i] << '\n';
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
