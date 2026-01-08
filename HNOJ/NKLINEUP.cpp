/*************************
  Author: Defy logic guy
  19:49:45 - 03/02/2025
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
#define NAME "NKLINEUP"

class SegmentTree
{
private:
    vector<int> tree, a;
    function<int(int, int)> combine;
    int identity;

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
        tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
    }

    int queryInternal(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return identity;
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) / 2;
        int left = queryInternal(2 * idx, l, mid, ql, qr);
        int right = queryInternal(2 * idx + 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }

public:
    SegmentTree(vector<int> &v, function<int(int, int)> f) : combine(f)
    {
        a = v;
        int n = a.size();
        tree.resize(4 * n);
        init(1, 0, n - 1);

        int test_min = combine(LLONG_MIN, LLONG_MAX);
        if (test_min == LLONG_MIN)
            identity = LLONG_MAX;
        else
            identity = LLONG_MIN;
    }

    int query(int ql, int qr)
    {
        return queryInternal(1, 0, a.size() - 1, ql, qr);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree _max(a, [](int x, int y)
                     { return max(x, y); });
    SegmentTree _min(a, [](int x, int y)
                     { return min(x, y); });

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int max_val = _max.query(l, r);
        int min_val = _min.query(l, r);
        cout << (max_val - min_val) << endl;
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