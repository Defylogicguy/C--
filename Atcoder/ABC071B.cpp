/*************************
  Author: Defy logic guy
  23:39:54 - 20/06/2025
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
#define NAME "ABC071B"

void solve()
{
    string s;
    cin >> s;
    vector<bool> cnt(26, 0);
    for (char c : s)
        cnt[c - 'a'] = true;
    for (int i = 0; i < 26; i++)
        if (!cnt[i])
        {
            cout << char('a' + i);
            return;
        }
    cout << "None";
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
