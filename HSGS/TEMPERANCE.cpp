/*************************
  Author: Defy logic guy
  08:21:31 - 17/06/2025
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
#define NAME "TEMPERANCE"

void solve()
{
    string s;
    cin >> s;
    string tmp = "#";
    for (char c : s)
        tmp += c, tmp += '#';
    s = tmp;
    int n = s.size();
    vector<int> a(n, 0);
    int c = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int m = 2 * c - i;
        if (i < r)
            a[i] = min(a[m], r - i);
        while (i + a[i] < n && i - a[i] >= 0 && s[i + a[i]] == s[i - a[i]])
            a[i]++;
        if (i + a[i] > r)
        {
            c = i;
            r = i + a[i];
        }
    }

    cout << maxall(a) - 1 << ' ' << count(all(a), maxall(a)) << '\n';
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
