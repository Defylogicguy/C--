/*************************
  Author: Defy logic guy
  21:31:37 - 22/07/2025
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
#define NAME "VNOJ-KQUERY"

vector<vector<int>> tree;
vector<int> a;
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
    tree[idx].resize(tree[2 * idx].size() + tree[2 * idx + 1].size());
    merge(all(tree[2 * idx]), all(tree[2 * idx + 1]), tree[idx].begin());
}

int get(int idx, int l, int r, int ql, int qr, int k)
{
    if (ql > r or qr < l)
        return 0;
    if (ql <= l and r <= qr)
    {
        auto it = upper_bound(all(tree[idx]), k);
        return (int)(tree[idx].end() - it);
    }
    int mid = (l + r) / 2;
    return get(2 * idx, l, mid, ql, qr, k) + get(2 * idx + 1, mid + 1, r, ql, qr, k);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    tree.resize(4 * n + 4);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        cout << get(1, 0, n - 1, i - 1, j - 1, k) << '\n';
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
