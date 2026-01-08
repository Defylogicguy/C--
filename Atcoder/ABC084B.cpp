/*************************
  Author: Defy logic guy
  23:20:34 - 20/06/2025
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
#define NAME "ABC084B"

void solve()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    if (s[a] != '-')
    {
        cout << "No";
        return;
    }

    for (int i = a + 1; i < s.size(); i++)
        if (!isdigit(s[i]))
        {
            cout << "No";
            return;
        }

    for (int i = 0; i < a; i++)
        if (!isdigit(s[i]))
        {
            cout << "No";
            return;
        }

    cout << "Yes";
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
