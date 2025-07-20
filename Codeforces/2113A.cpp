/*************************
  Author: Defy logic guy
  11:42:28 - 20/07/2025
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
#define NAME "2113A"

void solve()
{
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y)
    {
        swap(a, b);
        swap(x, y);
    }

    int ans = 0;

    if (k >= a)
    {
        int c = (k - a) / x + 1;
        ans += c;
        k -= c * x;
    }

    if (k >= b)
    {
        int c = (k - b) / y + 1;
        ans += c;
        k -= c * y;
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

    while (tt--)
        solve();
    return 0;
}
