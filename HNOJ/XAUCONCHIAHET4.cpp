/*************************
  Author: Defy logic guy
  11:08:08 - 22/08/2025
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
#define NAME "XAUCONCHIAHET4"

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (((s[i] - '0') * 10 + (s[i + 1] - '0')) % 4 == 0)
            ans += (i + 1);
    for (char c : s)
        ans += ((c - '0') % 4 == 0);
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
