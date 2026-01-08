/*************************
  Author: Defy logic guy
  22:09:47 - 26/07/2025
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
#define NAME "LIGHTOJ-ALL_POSSIBLE_INC_SUBSEQ"

vector<int> tree;

void upd(int idx, int l, int r, int pos, int x)
{
    if (l == r)
    {
        tree[idx] = (tree[idx] + x) % MOD;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        upd(2 * idx, l, mid, pos, x);
    else
        upd(2 * idx + 1, mid + 1, r, pos, x);
    tree[idx] = (tree[2 * idx] + tree[2 * idx + 1]) % MOD;
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (ql > r or l > qr)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int mid = l + r >> 1;
    return get(2 * idx, l, mid, ql, qr) + get(2 * idx + 1, mid + 1, r, ql, qr);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> c = a;
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    auto gget = [&](int x)
    {
        return lower_bound(all(c), x) - c.begin() + 1;
    };
    tree.assign(4 * (c.size() + 2), 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = get(1, 1, c.size(), 1, gget(a[i]) - 1);
        x = (x + 1) % MOD;
        upd(1, 1, c.size(), gget(a[i]), x);
        ans = (ans + x) % MOD;
    }
    cout << ans << '\n';
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
    {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}
