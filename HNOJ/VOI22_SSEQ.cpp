/*************************
  Author: Defy logic guy
  18:42:43 - 17/10/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define float double
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define maxall(x) *max_element(all(x))
// #define minall(x) *min_element(all(x))
// #define heap priority_queue
// #define pb push_back
// #define MOD 1000000007
#define NAME "SSEQ"

const int N = 1e6, maxn = 1e5;
int n, l[maxn], r[maxn], w[maxn];
vector<int> rem[N << 1 | 1];
long long tree[N << 3], lazy[N << 3];

void propagate(int idx)
{
    if (!lazy[idx])
        return;
    tree[idx << 1] += lazy[idx];
    tree[idx << 1 | 1] += lazy[idx];
    lazy[idx << 1] += lazy[idx];
    lazy[idx << 1 | 1] += lazy[idx];
    lazy[idx] = 0;
}

void upd(int idx, int l, int r, int ql, int qr, int x)
{
    if (qr < l or r < ql)
        return;
    if (ql <= l and r <= qr)
    {
        tree[idx] += x;
        lazy[idx] += x;
        return;
    }
    propagate(idx);
    int mid = l + r >> 1;
    upd(idx << 1, l, mid, ql, qr, x);
    upd(idx << 1 | 1, mid + 1, r, ql, qr, x);
    tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> w[i];
        rem[l[i] + N].emplace_back(i);
        upd(1, -N, N, r[i], N, +w[i]);
    }

    long long ans = LLONG_MIN;
    for (int i = -N; i <= N; i++)
    {
        for (int j : rem[i + N])
            upd(1, -N, N, r[j], N, -w[j]);
        ans = max(ans, tree[1]);
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
    // cout.tie(nullptr);

    // int tt = 1;
    // cin >> tt;

    // while (tt--)
        solve();

    return 0;
}
