/*************************
  Author: Defy logic guy
  14:46:51 - 02/02/2025
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
#define NAME "SEGG1"

vector<int> a, tree;

void init(int l, int r, int idx)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    init(l, mid, 2 * idx);
    init(mid + 1, r, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return LLONG_MAX;
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    return min(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n, m;
    cin >> n >> m;

    tree.resize(4 * n), a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(0, n - 1, 1);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            upd(1, 0, n - 1, x - 1, y);
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
