/*************************
  Author: Defy logic guy
  21:40:25 - 26/07/2025
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
#define MOD 5000000
#define NAME "VNOJ-INCVN"

vector<int> a, tree;
const int maxn = 1e5 + 7;
void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] = (tree[idx] + x) % MOD;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = (tree[2 * idx] + tree[2 * idx + 1]) % MOD;
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or l > qr)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = l + r >> 1;
    return (get(2 * idx, l, mid, ql, qr) + get(2 * idx + 1, mid + 1, r, ql, qr)) % MOD;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> inc(n, 1);
    for (int i = 2; i <= k; i++)
    {
        tree.assign(4 * maxn, 0);
        for (int j = 0; j < n; j++)
        {
            int t = get(1, 1, maxn, 1, a[j] - 1);
            upd(1, 1, maxn, a[j], inc[j]);
            inc[j] = t;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + inc[i]) % MOD;
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
