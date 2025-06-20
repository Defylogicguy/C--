/*************************
  Author: Defy logic guy
  23:50:42 - 20/06/2025
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
#define NAME "ABC127C"

void solve()
{
    int n, m;
    cin >> n >> m;
    int one = 1, two = n;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        b = min(b, n);
        one = max(one, a);
        two = min(two, b);
    }
    cout << max(0LL, two - one + 1) << "\n";
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
