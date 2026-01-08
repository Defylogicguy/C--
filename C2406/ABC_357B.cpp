/*************************
  Author: Defy logic guy
  20:09:37 - 14/01/2025
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
#define NAME "ABC_357B"

void solve()
{
    string s;
    cin >> s;

    int one = 0, two = 0;
    for (char c :s)
    {
        one += ('A' <= c and c <= 'Z');
        two += ('a' <= c and c <= 'z');
    }

    if (one > two)
        transform(all(s), s.begin(), ::toupper);
    else
        transform(all(s), s.begin(), ::tolower);
    cout << s;
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
