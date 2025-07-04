/*************************
  Author: Defy logic guy
  17:37:01 - 22/06/2025
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
#define NAME "ABC062B"

void solve()
{
    int h, w;
    cin >> h >> w;
    cout << string(w + 2, '#') << '\n';
    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        cout << "#" << s << "#\n";
    }
    cout << string(w + 2, '#') << '\n';
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
