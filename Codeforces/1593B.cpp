/*************************
  Author: Defy logic guy
  23:12:15 - 17/08/2025
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
#define NAME "1593B"

void solve()
{
    string s;
    cin >> s;
    int mn = INT_MAX;
    for (string t : {"00", "25", "50", "75"})
    {
        int n = s.size() - 1;
        int ans = 0;

        while (n >= 0 and s[n] != t[1])
        {
            n--;
            ans++;
        }

        if (n < 0)
            ans = min(ans, (int)INT_MAX);

        n--;

        while (n >= 0 and s[n] != t[0])
        {
            n--;
            ans++;
        }

        mn = min(mn, (n < 0 ? INT_MAX : ans));
    }
    cout << mn << '\n';
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
