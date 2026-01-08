/*************************
  Author: Defy logic guy
  23:17:19 - 29/05/2025
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
#define endl '\n'
#define NAME "CONTEST10_MIS"

vector<int> tree;

void upd(int idx, int l, int r, int pos, int val)
{
    if (l == r)
    {
        tree[idx] = max(tree[idx], val);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx + 1, l, mid, pos, val);
    else
        upd(2 * idx + 2, mid + 1, r, pos, val);
    tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return 0;
    if (ql <= l && r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    return max(query(2 * idx + 1, l, mid, ql, qr), query(2 * idx + 2, mid + 1, r, ql, qr));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l[i] = a[i] % 100;
    }

    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    map<int, int> mp;
    for (int i = 0; i < b.size(); i++)
        mp[b[i]] = i;

    tree.assign(4 * b.size(), 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = mp[a[i]];
        int res = 0;
        if (idx > 0)
            res = query(0, 0, b.size() - 1, 0, idx - 1);
        int cur = res + l[i];
        upd(0, 0, b.size() - 1, idx, cur);
        ans = max(ans, cur);
    }
    cout << ans << endl;
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
