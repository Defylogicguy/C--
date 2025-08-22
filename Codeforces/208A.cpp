/*************************
  Author: Defy logic guy
  20:50:27 - 21/08/2025
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
#define NAME "208A"

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
        if (i + 2 < s.size() && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
            s[i] = s[i + 1] = s[i + 2] = ' ';
    string t;
    bool flag = false;
    if (s[0] == ' ')
        flag = true;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == ' ' and s[i + 1] != ' ')
            t.pb(' ');
        else if (s[i] != ' ')
            t.pb(s[i]);
    if (s[s.size() - 1] != ' ')
        t.pb(s[s.size() - 1]);
    if (flag)
        t = t.substr(1, t.size() - 1);
    cout << t;
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
