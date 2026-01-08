/*************************
  Author: Defy logic guy
  08:59:17 - 21/06/2025
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
#define NAME "SECONDMAX"

int n, q;
vector<int> a;
vector<pair<int, int>> tree;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        tree[idx] = {a[l], a[l]}; 
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    vector<int> tmp = {tree[2 * idx].first, tree[2 * idx].second,
                       tree[2 * idx + 1].first, tree[2 * idx + 1].second};
    sort(rall(tmp));
    tmp.erase(unique(all(tmp)), tmp.end()); 
    tree[idx].first = tmp[0];
    tree[idx].second = (tmp.size() > 1 ? tmp[1] : LLONG_MIN);
}

pair<int, int> query(int idx, int l, int r, int u, int v)
{
    if (l > v || r < u)
        return {LLONG_MIN, LLONG_MIN};
    if (l >= u && r <= v)
        return tree[idx];
    int mid = (l + r) / 2;
    auto left = query(2 * idx, l, mid, u, v);
    auto right = query(2 * idx + 1, mid + 1, r, u, v);

    vector<int> tmp = {left.first, left.second, right.first, right.second};
    sort(rall(tmp));
    tmp.erase(unique(all(tmp)), tmp.end()); // Remove duplicates
    return {tmp[0], (tmp.size() > 1 ? tmp[1] : LLONG_MIN)};
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
        int l, r;
        cin >> l >> r;
        l--, r--;
        int res = query(1, 0, n - 1, l, r).second;
        cout << res << '\n';
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
