/*************************
  Author: Defy logic guy
  15:32:05 - 30/05/2025
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
#define endl '\n'
#define NAME "ABC068B"

void solve()
{
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        int cnt = 0;
        while (x % 2 == 0)
        {
            x /= 2;
            cnt++;
        }
        mx = max(mx, cnt);
    }

    cout << pow(2, mx) << endl;
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
