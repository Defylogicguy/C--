/*************************
  Author: Defy logic guy
  15:37:49 - 24/05/2025
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
#define endl '\n'
#define NAME "CONTEST10_DIVSUB"

void solve()
{
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    
    int ans = 0;

    if (p == 2 or p == 5)
    {
        for (int i = 0; i < n; i++)
            if ((s[i] - '0') % p == 0)
                ans += i + 1;
    }
    else
    {
        map<int, int> mp;
        mp[0] = 1;

        int cur = 0;
        int ten = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            cur = (cur + (s[i] - '0') * ten) % p;
            ans += mp[cur];
            mp[cur]++;
            ten = (ten * 10) % p;
        }
    }

    cout << ans << endl;
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
