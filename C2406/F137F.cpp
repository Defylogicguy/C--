/*************************
  Author: Defy logic guy
  23:22:05 - 11/04/2025
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
#define NAME "F137F"

void solve()
{
    string n;
    int k;
    cin >> n >> k;
    if (k == 1)
        cout << "YES\n";
    else if (k == 2)
        cout << ((n.back() - '0') & 1 ? "NO\n" : "YES\n");
    else if (k == 3)
    {
        int sum = 0;
        for (char c : n)
            sum += c - '0';
        cout << ((sum % 3 == 0) and ((n.back() - '0') % 2 == 0) ? "YES\n" : "NO\n");
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
