/*************************
  Author: Defy logic guy
  16:07:05 - 01/08/2025
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
#define NAME "SCARRAY"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    vector<int> b(n + 1, 0);
    b[0] = 1;
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        b[i] = sum;
        if (i >= k)
            sum = (sum - b[i - k] + MOD) % MOD;
        sum = (sum + b[i]) % MOD;
    }
    int ans = 1;
    int l = 0;
    while (l < n)
    {
        int r = l;
        while (r + 1 < n && a[r + 1] == a[l])
            r++;
        ans = (1LL * ans * b[r - l + 1]) % MOD;
        l = r + 1;
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
