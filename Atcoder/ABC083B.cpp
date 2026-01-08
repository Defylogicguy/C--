/*************************
  Author: Defy logic guy
  14:19:24 - 23/06/2025
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
#define NAME "ABC083B"

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    auto cnt = [](int x) -> int
    {
        int ans = 0;
        while (x)
            ans += x % 10, x /= 10;
        return ans;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = cnt(i);
        ans += (a <= x and x <= b ? i : 0);
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
