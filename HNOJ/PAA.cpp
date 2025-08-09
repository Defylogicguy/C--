/*************************
  Author: Defy logic guy
  22:11:50 - 08/08/2025
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
#define NAME "PAA"

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
vector<int> cnt(maxn, 0);
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<Query> q(m);
    for (int i = 0; i < m; i++)
        cin >> q[i].l >> q[i].r, q[i].l--, q[i].r--, q[i].idx = i;
    s = sqrt(n);
    sort(all(q));
    vector<int> res(m);
    int cl = 0, cr = -1;
    int cur = 0;
    auto add = [&](int i)
    {
        int idk = cnt[a[i]];
        cur -= idk * idk * a[i];
        cnt[a[i]]++;
        cur += (idk + 1) * (idk + 1) * a[i];
    };
    auto del = [&](int i)
    {
        int idk = cnt[a[i]];
        cur -= idk * idk * a[i];
        cnt[a[i]]--;
        cur += (idk - 1) * (idk - 1) * a[i];
    };
    for (int i = 0; i < m; i++)
    {
        while (cl > q[i].l)
            add(--cl);
        while (cr < q[i].r)
            add(++cr);
        while (cl < q[i].l)
            del(cl++);
        while (cr > q[i].r)
            del(cr--);
        res[q[i].idx] = cur;
    }
    for (int i = 0; i < m; i++)
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
