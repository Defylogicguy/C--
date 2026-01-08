/*************************
  Author: Defy logic guy
  20:25:36 - 26/07/2025
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
#define NAME "CSES-1651"

vector<int> a, tree, lazy;

void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }
    int mid = l + r >> 1;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = 0;
}

void upd(int idx, int l, int r, int ql, int qr, int x)
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
    if (r < ql or l > qr)
        return;
    if (ql <= l and r <= qr)
    {
        lazy[idx] += x;
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
        return;
    }
    int mid = l + r >> 1;
    upd(2 * idx, l, mid, ql, qr, x);
    upd(2 * idx + 1, mid + 1, r, ql, qr, x);
}

int get(int idx, int l, int r, int pos)
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
    if (l == r)
        return tree[idx];
    int mid = l + r >> 1;
    if (pos <= mid)
        return get(2 * idx, l, mid, pos);
    else
        return get(2 * idx + 1, mid + 1, r, pos);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n);
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            upd(1, 0, n - 1, a - 1, b - 1, u);
        }
        else
        {
            int k;
            cin >> k;
            cout << get(1, 0, n - 1, k - 1) << '\n';
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
