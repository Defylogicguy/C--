/*************************
  Author: Defy logic guy
  13:52:31 - 30/08/2025
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
#define NAME "2114B"

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<int, int> mp;
    for (char c : s)
        mp[c]++;
    int mn = max(mp['1'], mp['0']) - n / 2;
    int mx = mp['1'] / 2 + mp['0'] / 2;
    if (k >= mn and (k - mn) % 2 == 0 and k <= mx)
        cout << "YES\n";
    else
        cout << "NO\n";
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
