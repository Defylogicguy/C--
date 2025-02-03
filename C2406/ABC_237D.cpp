/*************************
  Author: Defy logic guy
  22:04:40 - 01/02/2025
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
#define NAME "ABC_237D"

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    deque<int> l, r;
    int cur = 0;
    for (int i = 1; i <= n; i++)
        if (s[i - 1] == 'L')
        {
            r.push_front(cur);
            cur = i;
        }
        else
        {
            l.pb(cur);
            cur = i;
        }
    for (int  i : l)
        cout << i << ' ';
    cout << cur << ' ';
    for (int i : r)
        cout << i << ' ';
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
