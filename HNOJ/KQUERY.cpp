/*************************
  Author: Defy logic guy
  07:57:10 - 04/02/2025
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
#define NAME "KQUERY"

vector<int> a;
vector<vector<int>> tree;

void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = {a[l]};
        return;
    }

    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    merge(all(tree[2 * idx]), all(tree[2 * idx + 1]), back_inserter(tree[idx]));
}

int query(int idx, int l, int r, int ql, int qr, int k)
{
    if (ql > r or qr < l)
        return 0;

    if (ql <= l and r <= qr)
        return tree[idx].end() - upper_bound(all(tree[idx]), k);

    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr, k) + query(2 * idx + 1, mid + 1, r, ql, qr, k);
}

void solve()
{
    int n;
    cin >> n;

    a.resize(n);
    tree.resize(4 * n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 0, n - 1, l - 1, r - 1, k) << endl;
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
