/*************************
  Author: Defy logic guy
  16:29:32 - 22/06/2025
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
#define NAME "ABC124C"

void solve()
{
    string s;
    cin >> s;
    string tmp;
    for (int i = 0; i < s.size(); i++)
        tmp += ((i & 1) + '0');
    int ans = LLONG_MAX;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != tmp[i])
            cnt++;
    ans = min(ans, cnt);
    tmp.clear();
    for (int i = 0; i < s.size(); i++)
        tmp += ((i & 1) ^ 1 + '0');
    cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != tmp[i])
            cnt++;
    ans = min(ans, cnt);
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
