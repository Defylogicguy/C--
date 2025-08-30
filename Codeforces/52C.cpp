/*************************
  Author: Defy logic guy
  12:51:31 - 05/09/2025
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
#define NAME "52C"

vector<int> tree, lazy, a;
void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }
    int mid = l + r >> 1;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}

void push(int idx, int l, int r)
{
    if (lazy[idx])
    {
        tree[idx] += lazy[idx];
        if (l != r)
        {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

int get(int idx, int l, int r, int ql, int qr)
{
    push(idx, l, r);
    if (l > qr or r < ql)
        return LLONG_MAX;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = l + r >> 1;
    return min(get(2 * idx, l, mid, ql, qr), get(2 * idx + 1, mid + 1, r, ql, qr));
}

void upd(int idx, int l, int r, int ql, int qr, int val)
{
    push(idx, l, r);
    if (l > qr or r < ql)
        return;
    if (ql <= l and r <= qr)
    {
        lazy[idx] += val;
        push(idx, l, r);
        return;
    }
    int mid = l + r >> 1;
    upd(2 * idx, l, mid, ql, qr, val);
    upd(2 * idx + 1, mid + 1, r, ql, qr, val);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n), tree.resize(4 * n), lazy.assign(4 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    int m;
    cin >> m;
    cin.ignore();
    while (m--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int l, r, c;
        ss >> l >> r;
        if (ss >> c)
        {
            if (l <= r)
                upd(1, 0, n - 1, l, r, c);
            else
                upd(1, 0, n - 1, l, n - 1, c), upd(1, 0, n - 1, 0, r, c);
        }
        else
        {
            int ans = 0;
            if (l <= r)
                ans = get(1, 0, n - 1, l, r);
            else
                ans = min(get(1, 0, n - 1, l, n - 1), get(1, 0, n - 1, 0, r));
            cout << ans << '\n';
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
