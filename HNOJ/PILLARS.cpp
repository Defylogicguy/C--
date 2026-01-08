/*************************
  Author: Defy logic guy
  14:37:53 - 05/09/2025
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
#define NAME "PILLARS"

struct Segtree
{
    vector<pair<int, int>> tree;
    void init(int n) { tree.assign(4 * n, {0, -1}); }
    void upd(int idx, int l, int r, int pos, pair<int, int> val)
    {
        if (l == r)
        {
            tree[idx] = max(tree[idx], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(2 * idx, l, mid, pos, val);
        else
            upd(2 * idx + 1, mid + 1, r, pos, val);
        tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
    }
    pair<int, int> get(int idx, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return {0, -1};
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) >> 1;
        return max(get(2 * idx, l, mid, ql, qr), get(2 * idx + 1, mid + 1, r, ql, qr));
    }
};

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        t.pb(a[i]);
        t.pb(a[i] + d);
        t.pb(a[i] - d);
    }

    sort(all(t));
    t.erase(unique(all(t)), t.end());

    auto f = [&](int x)
    { return lower_bound(all(t), x) - t.begin(); };

    Segtree seg;
    seg.init(t.size());

    vector<int> dp(n, 1), path(n, -1);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> mx = {0, -1};
        if (a[i] - d >= 0)
            mx = max(mx, seg.get(1, 0, t.size() - 1, 0, f(a[i] - d)));
        if (a[i] + d <= t.back())
            mx = max(mx, seg.get(1, 0, t.size() - 1, f(a[i] + d), t.size() - 1));
        dp[i] = mx.first + 1;
        path[i] = mx.second;
        seg.upd(1, 0, t.size() - 1, f(a[i]), {dp[i], i});
    }

    int mx = 0, pos = -1;
    for (int i = 0; i < n; i++)
        if (dp[i] > mx)
        {
            mx = dp[i];
            pos = i;
        }

    vector<int> res;
    while (pos != -1)
    {
        res.pb(pos + 1);
        pos = path[pos];
    }

    reverse(all(res));
    cout << res.size() << '\n';
    for (auto i : res)
        cout << i << ' ';
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
