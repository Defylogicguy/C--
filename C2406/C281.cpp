/*************************
  Author: Defy logic guy
  20:56:27 - 12/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "C281"

void solve()
{
    string s;
    cin >> s;
    int sum = 0;
    int zer = 0, one = 0, two = 0;
    for (char c : s)
    {
        sum += c - '0';
        if ((c - '0') % 3 == 0)
            zer++;
        else if ((c - '0') % 3 == 1)
            one++;
        else
            two++;
    }

    if (sum % 3 == 0)
        cout << 0;
    else if (sum % 3 == 1)
    {
        if (one >= 1 and s.size() > 1)
            cout << 1;
        else if (two >= 2 and s.size() > 2)
            cout << 2;
        else
            cout << -1;
    }
    else
    {
        if (two >= 1 and s.size() > 1)
            cout << 1;
        else if (one >= 2 and s.size() > 2)
            cout << 2;
        else
            cout << -1;
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
