/*************************
  Author: Defy logic guy
  20:38:34 - 03/02/2025
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
#define NAME "INVERSIONEASY"

vector<int> a, tree;

void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = 0;
        return;
    }

    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void upd(int idx, int l, int r, int node, int x)
{
    if (l == r)
    {
        tree[idx] += x;
        return;
    }
    int mid = (l + r) / 2;
    if (node <= mid)
        upd(2 * idx, l, mid, node, x);
    else
        upd(2 * idx + 1, mid + 1, r, node, x);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    int _max = *max_element(all(a));
    tree.resize(4 * _max);
    init(1, 0, _max - 1);

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += query(1, 0, _max - 1, 0, a[i] - 2);
        upd(1, 0, _max - 1, a[i] - 1, 1);
    }
    cout << ans << endl;
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