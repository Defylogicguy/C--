/*************************
  Author: Defy logic guy
  22:09:49 - 26/06/2025
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
#define NAME "ARC058A"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> t(m);
    for (int i = 0; i < m; i++)
        cin >> t[i];
    auto valid = [t](int x)
    {
        while (x)
        {
            int idk = x % 10;
            if (find(all(t), idk) != t.end())
                return false;
            x /= 10;
        }
        return true;
    };

    int ans = n;
    while (!valid(ans))
        ans++;
    cout << ans;
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
