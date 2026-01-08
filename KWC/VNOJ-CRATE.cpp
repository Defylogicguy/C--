/*************************
  Author: Defy logic guy
  20:48:18 - 26/07/2025
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
#define NAME "VNOJ-CRATE"

struct inp
{
    int a, h, idx;
    const bool operator<(inp other) { return a == other.a ? h < other.h : a < other.a; }
    const bool operator==(inp other) { return a == other.a and h == other.h; }
};

vector<int> tree, h;

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] += x;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or l > qr)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = l + r >> 1;
    return get(2 * idx, l, mid, ql, qr) + get(2 * idx + 1, mid + 1, r, ql, qr);
}

void solve()
{
    int n;
    cin >> n;
    vector<inp> a(n);
    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].a >> a[i].h, a[i].idx = i, h.pb(a[i].h);
    sort(all(h));
    h.erase(unique(all(h)), h.end());
    for (int i = 0; i < n; i++)
        a[i].h = lower_bound(all(h), a[i].h) - h.begin() + 1;
    sort(all(a));
    tree.assign(4 * (h.size() + 2), 0);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (i and a[i] == a[i - 1])
            ans[a[i].idx] = ans[a[i - 1].idx];
        else
            ans[a[i].idx] = get(1, 1, h.size(), 1, a[i].h);
        upd(1, 1, h.size(), a[i].h, 1);
    }
    for (int i : ans)
        cout << i << '\n';
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
