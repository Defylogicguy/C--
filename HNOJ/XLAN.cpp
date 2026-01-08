/*************************
  Author: Defy logic guy
  19:05:27 - 08/08/2025
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
#define NAME "XLAN"

int s;
struct Query
{
    int l, r, x, idx;
    Query(int l = 0, int r = 0, int x = 0, int idx = 0, int block = 0)
        : l(l), r(r), x(x), idx(idx) {}

    bool operator<(Query const &other) const
    {
        if (l / s != other.l / s)
            return l / s < other.l / s;
        if (l / s & 1)
            return r > other.r;
        else
            return r < other.r;
    }
};

const int maxn = 1e5 + 7;
vector<int> cnt(maxn), freq(maxn);
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<Query> qry;
    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        qry.pb(Query(l, r, x, i));
    }
    s = sqrt(n);
    sort(all(qry));
    int cl = 0, cr = -1;
    vector<int> res(n);
    for (int i = 0; i < q; i++)
    {
        int l = qry[i].l, r = qry[i].r;
        auto add = [&](int i)
        {
            int val = a[i];
            if (freq[val] > 0)
                cnt[freq[val]]--;
            freq[val]++;
            cnt[freq[val]]++;
        };
        auto rm = [&](int i)
        {
            int val = a[i];
            cnt[freq[val]]--;
            freq[val]--;
            if (freq[val] > 0)
                cnt[freq[val]]++;
        };
        while (cl > l)
            add(--cl);
        while (cr < r)
            add(++cr);
        while (cl < l)
            rm(cl++);
        while (cr > r)
            rm(cr--);
        if (qry[i].x <= n)
            res[qry[i].idx] = cnt[qry[i].x];
        else
            res[qry[i].idx] = 0;
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
