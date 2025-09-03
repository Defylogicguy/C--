/*************************
  Author: Defy logic guy
  13:22:21 - 03/09/2025
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
#define NAME "2014H"

inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

int s;
struct Query
{
    int l, r, idx, ord;
    Query(int l = 0, int r = 0, int idx = 0) : l(l), r(r), idx(idx), ord(gilbertOrder(l, r, 21, 0)) {}
    bool operator<(const Query &other) const { return ord < other.ord; }
};

const int maxn = 1e6 + 5;
int cnt[maxn];

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i]] = 0;
    vector<Query> v;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        v.pb(Query(l - 1, r - 1, i));
    }
    s = sqrt(n);
    sort(all(v));
    int cur = 0;
    auto add = [&](int pos)
    {
        int val = a[pos];
        cnt[val]++;
        cur += (cnt[val] & 1 ? 1 : -1);
    };
    auto rm = [&](int pos)
    {
        int val = a[pos];
        cnt[val]--;
        cur += (cnt[val] & 1 ? 1 : -1);
    };
    int cl = 0, cr = -1;
    vector<string> ans(q);
    for (int i = 0; i < q; i++)
    {
        int l = v[i].l, r = v[i].r;
        while (cl > l)
            add(--cl);
        while (cr < r)
            add(++cr);
        while (cl < l)
            rm(cl++);
        while (cr > r)
            rm(cr--);
        ans[v[i].idx] = (cur == 0 ? "YES" : "NO");
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
    cout.tie(nullptr);

    int tt = 1;
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
