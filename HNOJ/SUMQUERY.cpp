/*************************
  Author: Defy logic guy
  19:41:43 - 03/02/2025
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
#define NAME "SUMQUERY"

vector<int> a, tree;

void init(int l, int r, int idx)
{
    if (l == r)
    {
        tree[idx] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    init(l, mid, 2 * idx);
    init(mid + 1, r, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] = x;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int query(int idx, int l, int r, int st, int end)
{
    if (l > end || r < st)
        return 0;
    
    if (l >= st && r <= end)
        return tree[idx];
    
    int mid = (l + r) / 2; 
    return query(2 * idx, l, mid, st, end) + query(2 * idx + 1, mid + 1, r, st, end);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    a.resize(n), tree.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(0, n - 1, 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k, u;
            cin >> k >> u;
            upd(1, 0, n - 1, k - 1, u);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
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

