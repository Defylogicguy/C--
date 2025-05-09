/*************************
  Author: Defy logic guy
  13:43:43 - 13/02/2025
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
#define NAME "I have a sugar daddy and he's pretty gay"

vector<int> tree;
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
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
}

void upd(int idx, int l, int r, int ql, int qr, int val)
{
    if (l > qr || r < ql)
        return;
    if (ql <= l && r <= qr)
    {
        tree[idx] += val;
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
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    return max(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    tree.resize(4 * n);
    init(1, 0, n - 1);

    while (m--)
    {
        int u, v, k;
        cin >> u >> v >> k;
        upd(1, 0, n - 1, u - 1, v - 1, k);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
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
