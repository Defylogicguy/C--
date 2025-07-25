/*************************
 Author: Defy logic guy
20:31:42 - 22/07/2025
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
#define NAME "VNOJ-C11SEQ"

vector<int> tree, a;
int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or qr < l)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = (l + r) / 2;
    int le = get(2 * idx, l, mid, ql, qr);
    int ri = get(2 * idx + 1, mid + 1, r, ql, qr);
    return le + ri;
}

void upd(int idx, int l, int r, int pos)
{
    if (l == r)
    {
        tree[idx]++;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos);
    else
        upd(2 * idx + 1, mid + 1, r, pos);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    a.resize(n + 1);
    vector<int> pf;
    pf.pb(0);
    tree.assign(4 * (n + 2), 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
        pf.pb(a[i]);
    }
    sort(all(pf));
    pf.resize(unique(all(pf)) - pf.begin());
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i)
        {
            int ll = lower_bound(all(pf), a[i] - r) - pf.begin();
            int rr = upper_bound(all(pf), a[i] - l) - pf.begin() - 1;
            if (ll <= rr)
                ans += get(1, 0, pf.size() - 1, ll, rr);
        }
        upd(1, 0, pf.size() - 1, lower_bound(all(pf), a[i]) - pf.begin());
    }
    cout << ans;
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
