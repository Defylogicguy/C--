/*************************
  Author: Defy logic guy
  20:10:06 - 22/07/2025
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
#define NAME "VNOJ-NKINV"

vector<int> tree, a;
void upd(int idx, int l, int r, int pos)
{
    if (l == r)
    {
        tree[idx]++;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos);
    else
        upd(2 * idx + 1, mid + 1, r, pos);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or qr < l)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    int le = get(2 * idx, l, mid, ql, qr);
    int ri = get(2 * idx + 1, mid + 1, r, ql, qr);
    return le + ri;
}

const int maxn = 1e5;
void solve()
{
    int n;
    cin >> n;
    tree.assign(4 * maxn, 0);
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 1)
            ans += get(1, 0, maxn, 0, a[i] - 1);
        upd(1, 0, maxn, a[i]);
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
