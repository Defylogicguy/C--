/*************************
  Author: Defy logic guy
  09:09:05 - 15/02/2025
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
#define NAME "DEMXAU"

void solve()
{
    string s;
    int x;
    cin >> s >> x;
    int one = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i - 1] == 'a' and s[i] == 'b')
            one++;
    
    if (x == 1)
    {
        cout << one << endl;
        return;
    }

    bool idk = false;
    if (s[0] == 'b' and s[s.size() - 1] == 'a')
        idk = true;
    cout << one * x + idk * (x - 1) << endl;
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
