/*************************
  Author: Defy logic guy
  10:46:50 - 29/08/2025
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
#define NAME "CH9"

void solve()
{
    string s;
    cin >> s;
    int m = 0;
    for (char c : s)
        m = (m + (c - '0')) % 9;
    string mn = string(s.size(), '9');
    for (int i = 0; i < s.size(); i++)
        for (char ch = '0'; ch <= '9'; ch++)
        {
            int nm = (m - (s[i] - '0') + (ch - '0') + 9) % 9;
            if (nm == 0)
            {
                char o = s[i];
                s[i] = ch;
                mn = min(mn, s);
                s[i] = o;
            }
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
