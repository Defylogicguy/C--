/*************************
  Author: Defy logic guy
  20:08:10 - 26/07/2025
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
#define NAME "LIGHTOJ-CURIOUS_ROBIN_HOOD"

struct SegmentTree
{
    struct node
    {
        int val;
        node(int x = 0) { val = x; }
    };
    vector<int> tree, a;
    SegmentTree(vector<int> _a)
    {
        int n = _a.size();
        tree.assign(4 * n, 0);
        a = _a;
    }

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
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

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

    void del(int idx, int l, int r, int pos)
    {
        if (l == r)
        {
            cout << tree[idx] << '\n';
            tree[idx] = 0;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid)
            del(2 * idx, l, mid, pos);
        else
            del(2 * idx + 1, mid + 1, r, pos);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int sum(int idx, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) / 2;
        return sum(2 * idx, l, mid, ql, qr) + sum(2 * idx + 1, mid + 1, r, ql, qr);
    }
};

void solve(int testcase)
{
    cout << "Case " << testcase + 1 << ":\n";
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree seg(a);
    seg.init(1, 0, n - 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            cin >> i;
            seg.del(1, 0, n - 1, i);
        }
        else if (t == 2)
        {
            int i, v;
            cin >> i >> v;
            seg.upd(1, 0, n - 1, i, v);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << seg.sum(1, 0, n - 1, i, j) << '\n';
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
    cin >> tt;

    for (int i = 0; i < tt; i++)
        solve(i);
    return 0;
}
