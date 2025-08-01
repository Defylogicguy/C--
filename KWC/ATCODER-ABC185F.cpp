/*************************
  Author: Defy logic guy
  19:52:37 - 26/07/2025
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
#define NAME "ATCODER-ABC185F"

vector<int> a, tree;
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
    tree[idx] = (tree[2 * idx] ^ tree[2 * idx + 1]);
}

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] ^= x;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = (tree[2 * idx] ^ tree[2 * idx + 1]);
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    return (get(2 * idx, l, mid, ql, qr) ^ get(2 * idx + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n), tree.assign(4 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1)
            upd(1, 0, n - 1, x, y);
        else
            y--, cout << get(1, 0, n - 1, x, y) << '\n';
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
