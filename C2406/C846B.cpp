/*************************
  Author: Defy logic guy
  20:10:25 - 25/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "C846B"

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    sort(all(a));
    int sum = accumulate(all(a), 0ll);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int idk = m;
        int one = 0;
        idk -= i * sum;
        one += i * (k + 1);
        if (idk < 0)
            break;
        for (int j : a)
        {
            int two = min(idk / j, n - i);
            idk -= two * j;
            one += two;
        }
        ans = max(ans, one);
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
