/*************************
  Author: Defy logic guy
  21:20:21 - 26/07/2025
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
#define NAME "ATCODER-ABC399E"

vector<int> a, tree;

int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or l > qr)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = l + r >> 1;
    return max(get(2 * idx, l, mid, ql, qr), get(2 * idx + 1, mid + 1, r, ql, qr));
}

void upd(int idx, int l,int r,int pos, int x)
{
    if (l == r)
    {
        tree[idx] = max(tree[idx], x);
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
}

const int maxn = 5e5 + 7;
void solve()
{
    int n, d;
    cin >> n >> d;
    a.resize(n);
    tree.assign(4 * maxn, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i : a)
    {
        int l = max(0ll, i - d);
        int r = min(maxn - 1, i + d);
        int mx = get(1, 0, maxn - 1, l, r);
        upd(1, 0, maxn - 1, i, mx + 1);
    }
    cout << get(1, 0, maxn - 1, 0, maxn - 1);
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
