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
#define NAME "REPEATED_STRING"

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    for (int cur = 1; cur <= n; cur++)
    {
        string ans = s.substr(0, cur);
        string idk = "";
        while (idk.size() < n)
            idk += ans;
        if (idk.substr(0, n) == s)
        {
            cout << ans << '\n';
            return;
        }
    }
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
