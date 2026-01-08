/*************************
  Author: Defy logic guy
  14:37:06 - 21/06/2025
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
#define NAME "LMH_SLEDDOGS"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = (x + k - 1) / k;
        c[i] = a[i] * k - x;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[i] = (x + k - 1) / k;
        d[i] = b[i] * k - x;
    }

    int ans = accumulate(all(a), 0ll) + accumulate(all(b), 0ll);
    int j = n - 1;
    sort(all(c)), sort(all(d));
    for (int i = 0; i < n; i++)
        if (j >= 0 && c[i] + d[j] >= k)
            ans--, j--;
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
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
