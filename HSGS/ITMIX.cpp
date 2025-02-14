/*************************
  Author: Defy logic guy
  15:22:14 - 13/02/2025
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
#define NAME "ITMIX"

vector<int> a, tree, lazy;

int mod(int x) { return x - x / MOD * MOD; }
void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void add(int idx, int l, int r, int ql, int qr, int val)
{
    if (lazy[idx])
    {
        tree[idx] = mod(tree[idx] + mod(lazy[idx] * (r - l + 1)));
        if (l != r)
        {
            lazy[2 * idx] = mod(lazy[2 * idx] + lazy[idx]);
            lazy[2 * idx + 1] = mod(lazy[2 * idx + 1] + lazy[idx]);
        }
        lazy[idx] = 0;
    }

    if (l > qr || r < ql)
        return;
    if (ql <= l && r <= qr)
    {
        tree[idx] = mod(tree[idx] + mod(val * (r - l + 1)));
        if (l != r)
        {
            lazy[2 * idx] = mod(lazy[2 * idx] + val);
            lazy[2 * idx + 1] = mod(lazy[2 * idx + 1] + val);
        }
        return;
    }

    int mid = (l + r) / 2;
    add(2 * idx, l, mid, ql, qr, val);
    add(2 * idx + 1, mid + 1, r, ql, qr, val);
}

void mul(int idx, int l, int r, int ql, int qr, int val)
{
    if (lazy[idx])
    {
        tree[idx] = mod(tree[idx] + mod(lazy[idx] * (r - l + 1)));
        if (l != r)
        {
            lazy[2 * idx] = mod(lazy[2 * idx] + lazy[idx]);
            lazy[2 * idx + 1] = mod(lazy[2 * idx + 1] + lazy[idx]);
        }
        lazy[idx] = 0;
    }

    if (l > qr || r < ql)
        return;
    if (ql <= l && r <= qr)
    {
        tree[idx] = mod(tree[idx] * val);
        if (l != r)
        {
            lazy[2 * idx] = mod(lazy[2 * idx] * val);
            lazy[2 * idx + 1] = mod(lazy[2 * idx + 1] * val);
        }        
        return;
    }

    int mid = (l + r) / 2;
    mul(2 * idx, l, mid, ql, qr, val);
    mul(2 * idx + 1, mid + 1, r, ql, qr, val);
}

void assign(int idx, int l, int r, int ql, int qr, int val)
{
    if (lazy[idx])
    {
        lazy[idx] = 0;
        tree[idx] = mod(val * (r - l + 1));
        if (l != r)
        {
            lazy[2 * idx] = mod(val);
            lazy[2 * idx + 1] = mod(val);
        }
    }

    if (l > qr || r < ql)
        return;
    
    if (ql <= l and r <= qr)
        tree[idx] = 0;
}
int query(int idx, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql)
        return 0;
    if (lazy[idx])
    {
        tree[idx] = mod(tree[idx] + mod(lazy[idx] * (r - l + 1)));
        if (l != r)
        {
            lazy[2 * idx] = mod(lazy[2 * idx] + lazy[idx]); 
            lazy[2 * idx + 1] = mod(lazy[2 * idx + 1] + lazy[idx]);
        }
        lazy[idx] = 0;
    }

    if (ql <= l && r <= qr)
        return tree[idx];
    
    int mid = (l + r) / 2;
    return mod(query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n), tree.resize(4 * n), lazy.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t== 1)
        {
            int x;
            cin >> x;
            add(1, 0, n - 1, l - 1, r - 1, x);
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            mul(1, 0, n - 1, l - 1, r - 1, x);
        }
        else if (t == 3)
        {
            int x;
            cin >> x;

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
