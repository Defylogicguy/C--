/*************************
  Author: Defy logic guy
  22:23:41 - 05/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define pb push_back
#define MOD 1000000007
#define NAME "ATCODER-ABC340E"

vector<int> tree, a, lazy;

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
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void push(int idx, int l, int r)
{
    if (lazy[idx])
    {
        int mid = l + r >> 1;
        tree[2 * idx] += (mid - l + 1) * lazy[idx];
        tree[2 * idx + 1] += (r - mid) * lazy[idx];
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
        lazy[idx] = 0;
    }
}

void upd(int idx, int l, int r, int ql, int qr, int x)
{
    if (ql > r or qr < l)
        return;
    if (ql <= l and r <= qr)
    {
        tree[idx] += (r - l + 1) * x;
        lazy[idx] += x;
        return;
    }
    push(idx, l, r);
    int mid = l + r >> 1;
    upd(2 * idx, l, mid, ql, qr, x);
    upd(2 * idx + 1, mid + 1, r, ql, qr, x);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int get(int idx, int l, int r, int pos)
{
    if (l == r)
        return tree[idx];
    push(idx, l, r);
    int mid = l + r >> 1;
    if (pos <= mid)
        return get(2 * idx, l, mid, pos);
    else
        return get(2 * idx + 1, mid + 1, r, pos);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n), tree.assign(4 * n + 5, 0), lazy.assign(4 * n + 5, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(1, 0, n - 1);

    while (m--)
    {
        int b;
        cin >> b;

        int x = get(1, 0, n - 1, b);
        upd(1, 0, n - 1, b, b, -x);

        int full = x / n;
        if (full > 0)
            upd(1, 0, n - 1, 0, n - 1, full);

        int r = x % n;
        if (r == 0)
            continue;

        int l1 = (b + 1) % n;
        int r1 = (b + r) % n;

        if (l1 <= r1)
            upd(1, 0, n - 1, l1, r1, 1);
        else
        {
            upd(1, 0, n - 1, l1, n - 1, 1);
            upd(1, 0, n - 1, 0, r1, 1);
        }
    }

    for (int i = 0; i < n; i++)
        cout << get(1, 0, n - 1, i) << ' ';
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
