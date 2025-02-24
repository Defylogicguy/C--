/*************************
  Author: Defy logic guy
  20:10:34 - 22/02/2025
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
#define NAME "F43BG"

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 10; i++)
        cnt += (s[i] == '8');
    if (cnt <= (n - 11) / 2)
        cout << "NO\n";
    else
        cout << "YES\n";
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
