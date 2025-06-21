/*************************
  Author: Defy logic guy
  09:54:12 - 21/06/2025
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
#define NAME "PSQUERY"

struct node
{
    int sum, pre, suf, ans;
    node(int x = 0)
    {
        sum = x;
        pre = suf = ans = max(0LL, x);
    }
};

node merge(node a, node b)
{
    node res;
    res.sum = a.sum + b.sum;
    res.pre = max(a.pre, a.sum + b.pre);
    res.suf = max(b.suf, b.sum + a.suf);
    res.ans = max({a.ans, b.ans, a.suf + b.pre});
    return res;
}

int n, q;
vector<int> a;
vector<node> tree;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = node(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
}

node query(int idx, int l, int r,int ql, int qr)
{
    if (ql > r || qr < l)
        return node(0);
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    node left = query(2 * idx, l, mid, ql, qr);
    node right = query(2 * idx + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] = node(x);
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
}

void solve()
{
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    tree.resize(4 * n);
    build(1, 0, n - 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k, u;
            cin >> k >> u;
            k--;
            upd(1, 0, n - 1, k, u);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            node res = query(1, 0, n - 1, l, r);
            cout << res.pre << '\n';
        }   
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
