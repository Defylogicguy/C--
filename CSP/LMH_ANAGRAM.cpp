/*************************
  Author: Defy logic guy
  14:35:51 - 21/06/2025
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
#define NAME "LMH_ANAGRAM"

void solve()
{
    string s, t;
    cin >> s >> t;
    int ans = LLONG_MAX;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        for (int k = 0; k < s.size(); k++)
            if (j < s.size() and s[j] == t[k])
                j++;
        ans = min(ans, (int)s.size() - j + i);
    }
    cout << ans << '\n';
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
