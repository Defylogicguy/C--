/*************************
  Author: Defy logic guy
  10:57:06 - 21/06/2025
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
#define NAME "BRACKETTT"

string s;
vector<pair<int, int>> tree;

pair<int, int> merge(pair<int, int> a, pair<int, int> b)
{
    int matched = min(a.first, b.second);
    return {a.first + b.first - matched, a.second + b.second - matched};
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = s[l - 1] == '(' ? make_pair(1, 0) : make_pair(0, 1);
        return;
    }

    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
}

pair<int, int> query(int idx, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return {0, 0}; 
    if (ql <= l && r <= qr)
        return tree[idx];

    int mid = (l + r) / 2;
    auto left = query(idx * 2, l, mid, ql, qr);
    auto right = query(idx * 2 + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}

void solve()
{
    cin >> s;
    int m;
    cin >> m;
    tree.resize((s.size() + 1) * 4);
    build(1, 1, s.size());
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        pair<int, int> res = query(1, 1, s.size(), l, r);
        cout << r - l + 1 - (res.first + res.second) << '\n';
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
