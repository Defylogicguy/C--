/*************************
  Author: Defy logic guy
  16:14:24 - 22/06/2025
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
#define NAME "AGC002A"

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a <= 0 and b >= 0)
    {
        cout << "Zero\n";
        return;
    }

    bool flag = false;
    if (a < 0 and b < 0)
        flag = (b - a + 1) % 2 == 0;
    else if (a > 0 and b > 0)
        flag = true;
    cout << (flag ? "Positive\n" : "Negative\n");
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
