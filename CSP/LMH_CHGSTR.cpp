/*************************
  Author: Defy logic guy
  15:23:50 - 19/07/2025
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
#define NAME "LMH_CHGSTR"

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<char> v(26);
    for (int i = 0; i < 26; i++)
        v[i] = 'a' + i;
    while (m--)
    {
        char a, b;
        cin >> a >> b;
        for (int i = 0; i < 26; i++)
            if (v[i] == a)
                v[i] = b;
    }
    for (char &c : s)
        c = v[c - 'a'];
    cout << s << '\n';
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
