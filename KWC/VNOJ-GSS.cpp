/*************************
  Author: Defy logic guy
  21:25:51 - 22/07/2025
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
#define NAME "VNOJ-GSS"

struct node
{
    int sum, pf, sf, ans;
    node(int _sum = 0, int _pf = 0, int _sf = 0, int _ans = 0) : sum(_sum), pf(_pf), sf(_sf), ans(_ans) {};
    const node operator+(const node &x)
    {
        node i;
        i.sum = sum + x.sum;
        i.pf = max(pf, sum + x.pf);
        i.sf = max(x.sf, x.sum + sf);
        i.ans = max({ans, x.ans, sf + x.pf});
        return i;
    }
};
vector<node> tree;
vector<int> a;
void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = node(a[l], a[l], a[l], a[l]);
        return;
    }
    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

node get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or qr < l)
        return node(0, LLONG_MIN / 4, LLONG_MIN / 4, LLONG_MIN / 4);
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    node le = get(2 * idx, l, mid, ql, qr);
    node ri = get(2 * idx + 1, mid + 1, r, ql, qr);
    return le + ri;
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    tree.assign(4 * n, node());
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 0, n - 1, l - 1, r - 1).ans << '\n';
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
