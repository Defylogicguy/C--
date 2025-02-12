/*************************
  Author: Defy logic guy
  19:50:54 - 11/02/2025
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
#define NAME "ABC_311B"

bool check(vector<string> s, int idx)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i][idx] == 'x')
            return false;
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int cur = 0, _max = 0;
    for (int i = 0; i < m; i++)
        if (check(s, i))
            cur++;
        else    
        {
            _max = max(_max, cur);
            cur = 0;
        }
    _max = max(_max, cur);
    cout << _max << endl;
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
