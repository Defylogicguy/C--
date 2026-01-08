/*************************
  Author: Defy logic guy
  19:52:33 - 22/07/2025
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
#define NAME "VNOJ-SEGTREE_ITMED"

vector<int> tree, a;
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
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or qr < l)
        return LLONG_MIN;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    int le = get(2 * idx, l, mid, ql, qr);
    int ri = get(2 * idx + 1, mid + 1, r, ql, qr);
    return max(le, ri);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    tree.assign(4 * n, 0);
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = max(a[i], (!i ? 0 : get(1, 0, n - 1, max(0ll, i - k), i - 1)) + a[i]);
        upd(1, 0, n - 1, i, x);
        ans = max(ans, x);
    }
    cout << ans;
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
