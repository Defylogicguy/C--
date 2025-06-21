/*************************
  Author: Defy logic guy
  08:58:20 - 21/06/2025
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
#define NAME "DHBB2023_RDAT"

struct node
{
    int one, two;
};

vector<node> tree;
node merge(node left, node right)
{
    vector<int> v = {left.one, left.two, right.one, right.two};
    sort(rall(v));
    return {v[0], v[1]};
}

void build(int idx, int l, int r, const vector<int> &a)
{
    if (l == r)
    {
        tree[idx] = {a[l], LLONG_MIN};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid, a);
    build(2 * idx + 2, mid + 1, r, a);
    tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
}

node query(int idx, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return {LLONG_MIN, LLONG_MIN};

    if (ql <= l && r <= qr)
        return tree[idx];

    int mid = (l + r) / 2;
    node left = query(2 * idx + 1, l, mid, ql, qr);
    node right = query(2 * idx + 2, mid + 1, r, ql, qr);
    return merge(left, right);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    tree.resize(4 * n);
    build(0, 0, n - 1, a);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        node res = query(0, 0, n - 1, l, r);
        cout << res.one + res.two << endl;
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
