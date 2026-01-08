/*************************
  Author: Defy logic guy
  15:36:46 - 15/03/2025
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
#define NAME "ZFUNC"

vector<int> zf(string s)
{
    int n = s.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++)
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
    return z;
}

void solve()
{
    string s;
    cin >> s;
    vector<int> z = zf(s);
    cout << s.size() << ' ';
    for (int i = 1; i < z.size(); i++)
        cout << z[i] << ' ';
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
