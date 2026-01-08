/*************************
  Author: Defy logic guy
  14:07:04 - 13/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "An onion and a 14-inch cock, both made me cry"

vector<int> a, tree, lazy;

void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
}

void upd(int idx, int l, int r, int ql, int qr, int val)
{
    if (lazy[idx])
    {
        tree[idx] += lazy[idx];
        if (l != r)
        {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l > qr || r < ql)
        return;

    if (ql <= l && r <= qr)
    {
        tree[idx] += val;
        if (l != r)
        {
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    upd(2 * idx, l, mid, ql, qr, val);
    upd(2 * idx + 1, mid + 1, r, ql, qr, val);
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql)
        return LLONG_MIN;
    if (lazy[idx])
    {
        tree[idx] += lazy[idx];
        if (l != r)
        {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    return max(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n;
    cin >> n;

    a.resize(n), tree.resize(4 * n), lazy.resize(4 * n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            upd(1, 0, n - 1, l - 1, r - 1, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
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
