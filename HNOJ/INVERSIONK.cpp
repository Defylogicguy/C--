/*************************
  Author: Defy logic guy
  18:43:44 - 01/08/2025
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
#define MOD 1000000000
#define NAME "INVERSIONK"

const int maxn = 1e4 + 7;
vector<vector<int>> bit(11, vector<int>(maxn));

void upd(int k, int idx, int x, int n)
{
    while (idx <= n)
    {
        bit[k][idx] += x;
        bit[k][idx] %= MOD;
        idx += idx & -idx;
    }
}

int sum(int k, int idx)
{
    int ans = 0;
    while (idx)
    {
        ans += bit[k][idx];
        ans %= MOD;
        idx -= idx & -idx;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], t[i] = a[i];
    sort(all(t));
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(all(t), a[i]) - t.begin() + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        upd(1, a[i], 1, n);
        for (int j = 1; j < k; j++)
            upd(j + 1, a[i], sum(j, a[i] - 1), n);
    }
    cout << sum(k, n);
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
