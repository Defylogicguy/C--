/*************************
  Author: Defy logic guy
  14:03:32 - 22/03/2025
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
#define NAME "CSPHN_NB_XAUHN"
void solve()
{
    string s;
    cin >> s;

    for (int i = 1; i <= s.size(); i++)
    {
        if (s.size() % i != 0)
            continue;
        string cur = s.substr(0, i);
        bool flag = true;
        for (int j = i; j < s.size(); j += i)
            if (s.substr(j, i) != cur)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            cout << cur;
            return;
        }
    }
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
