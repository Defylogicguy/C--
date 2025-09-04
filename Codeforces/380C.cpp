/*************************
  Author: Defy logic guy
  20:09:57 - 03/09/2025
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
#define NAME "380C"

struct node
{
    int a, b, c;
    node(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
    node operator+(const node &o)
    {
        int k = min(b, o.c);
        return node(a + o.a + k, b + o.b - k, c + o.c - k);
    }
};

vector<node> tree;
string s;

void init(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = s[l] == '(' ? node(0, 1, 0) : node(0, 0, 1);
        return;
    }
    int mid = l + r >> 1;
    init(2 * idx, l, mid);
    init(2 * idx + 1, mid + 1, r);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

node get(int idx, int l, int r, int ql, int qr)
{
    if (r < ql or qr < l)
        return node();
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = l + r >> 1;
    return get(2 * idx, l, mid, ql, qr) + get(2 * idx + 1, mid + 1, r, ql, qr);
}

void solve()
{
    cin >> s;
    tree.resize(s.size() * 4);
    init(1, 0, s.size() - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 0, s.size() - 1, l - 1, r - 1).a * 2 << '\n';
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
