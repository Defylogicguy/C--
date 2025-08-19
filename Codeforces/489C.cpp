/*************************
  Author: Defy logic guy
  22:23:18 - 18/08/2025
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
#define NAME "489C"

void solve()
{
    int m, s;
    cin >> m >> s;
    int t = s;
    if (s == 0 and m != 1)
    {
        cout << "-1 -1\n";
        return;
    }
    if (m * 9 < s)
    {
        cout << "-1 -1\n";
        return;
    }
    string ans = "";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 10; j++)
            if ((i > 0 or j > 0 or (m == 1 and j == 0)) and ((s - j) >= 0 and (s - j) <= 9 * (m - i - 1)))
            {
                ans += string(1, (j + '0'));
                s -= j;
                break;
            }
    cout << ans << ' ';
    ans = "";
    s = t;
    for (int i = 0; i < m; i++)
        for (int j = 9; j >= 0; j--)
            if ((i > 0 or j > 0 or (m == 1 and j == 0)) and ((s - j) >= 0 and (s - j) <= 9 * (m - i - 1)))
            {
                ans += string(1, (j + '0'));
                s -= j;
                break;
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
