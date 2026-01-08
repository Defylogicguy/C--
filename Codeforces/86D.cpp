/*************************
  Author: Defy logic guy
  10:10:47 - 04/09/2025
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
#define NAME "86D"

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

const int maxn = 1e6 + 5;
int cnt[maxn];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    s = sqrt(n);
    vector<Query> v;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        v.pb(Query(l - 1, r - 1, i));
    }
    sort(all(v));
    vector<int> res(m);
    int cl = 0, cr = -1;
    int cur = 0;
    auto add = [&](int pos)
    {
        int x = a[pos];
        cur -= cnt[x] * cnt[x] * x;
        cnt[x]++;
        cur += cnt[x] * cnt[x] * x;
    };
    auto rm = [&](int pos)
    {
        int x = a[pos];
        cur -= cnt[x] * cnt[x] * x;
        cnt[x]--;
        cur += cnt[x] * cnt[x] * x;
    };
    for (auto i : v)
    {
        int l = i.l, r = i.r;
        while (cr < r)
            add(++cr);
        while (cr > r)
            rm(cr--);
        while (cl < l)
            rm(cl++);
        while (cl > l)
            add(--cl);
        res[i.idx] = cur;
    }
    for (int i : res)
        cout << i << '\n';
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
