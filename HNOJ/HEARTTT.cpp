/*************************
  Author: Defy logic guy
  20:26:29 - 03/09/2025
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
#define NAME "HEARTTT"

struct node
{
    int a, b, c;
    node(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
    node operator+(const node &o) const
    {
        int k = min(b, o.c);
        return node(a + o.a + k, b + o.b - k, c + o.c - k);
    }
};

vector<node> tree;
vector<node> treeF;
vector<char> lazy;
string s;

void apply_flip(int idx)
{
    swap(tree[idx], treeF[idx]);
}

void push(int idx, int l, int r)
{
    if (!lazy[idx])
        return;
    apply_flip(idx);
    if (l != r)
    {
        lazy[2 * idx] ^= 1;
        lazy[2 * idx + 1] ^= 1;
    }
    lazy[idx] = 0;
}

void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = s[l] == '<' ? node(0, 1, 0) : node(0, 0, 1);
        treeF[idx] = s[l] == '<' ? node(0, 0, 1) : node(0, 1, 0);
        return;
    }
    int mid = (l + r) >> 1;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    treeF[idx] = treeF[2 * idx] + treeF[2 * idx + 1];
}

node get(int idx, int l, int r, int ql, int qr)
{
    push(idx, l, r);
    if (r < ql || qr < l)
        return node();
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) >> 1;
    return get(2 * idx, l, mid, ql, qr) + get(2 * idx + 1, mid + 1, r, ql, qr);
}

void upd(int idx, int l, int r, int ql, int qr)
{
    push(idx, l, r);
    if (r < ql || qr < l)
        return;
    if (ql <= l && r <= qr)
    {
        lazy[idx] ^= 1;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * idx, l, mid, ql, qr);
    upd(2 * idx + 1, mid + 1, r, ql, qr);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    treeF[idx] = treeF[2 * idx] + treeF[2 * idx + 1];
}

void solve()
{
    int n, q;
    cin >> n >> q >> s;
    tree.assign(4 * n + 5, node());
    treeF.assign(4 * n + 5, node());
    lazy.assign(4 * n + 5, 0);
    init(1, 0, n - 1);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            upd(1, 0, n - 1, l - 1, r - 1);
        else
            cout << get(1, 0, n - 1, l - 1, r - 1).a * 2 << '\n';
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
