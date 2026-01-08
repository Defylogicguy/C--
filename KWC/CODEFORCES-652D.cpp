/*************************
  Author: Defy logic guy
  20:07:25 - 29/07/2025
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
#define NAME "CODEFORCES-652D"

struct node
{
    int l, r, idx;
    node(int l = -1, int r = -1, int idx = -1) : l(l), r(r), idx(idx) {}
    bool operator<(node &o) { return o.l == l ? o.r < r : o.l > l; }
};

struct Fenwreck
{
    vector<int> a;
    int n;
    Fenwreck(int _n = 0)
    {
        n = _n;
        a.resize(n);
    }
    void upd(int x, int v)
    {
        while (x < n)
        {
            a[x] += v;
            x += (x & -x);
        }
    }
    int get(int x)
    {
        int res = 0;
        while (x)
        {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r, a[i].idx = i;
    vector<int> r;
    for (int i = 0; i < n; i++)
        r.pb(a[i].r);
    sort(all(r));
    map<int, int> mp;
    int idx = 1;
    for (int i : r)
        if (!mp[i])
            mp[i] = idx++;
    sort(all(a), [](node &a, node &b)
         { return a < b; });
    Fenwreck f(idx + 2);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int idk = mp[a[i].r];
        ans[a[i].idx] = f.get(idk);
        f.upd(idk, 1);
    }
    for (int i = 0; i < n; i++)
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
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
