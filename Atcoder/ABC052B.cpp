/*************************
  Author: Defy logic guy
  23:19:03 - 20/06/2025
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
#define NAME "ABC052B"

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
            cur++;
        else if (s[i] == 'D')
            cur--;
        mx = max(mx, cur);
    }
    cout << mx;
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
