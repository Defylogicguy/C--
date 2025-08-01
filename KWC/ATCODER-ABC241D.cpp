/*************************
  Author: Defy logic guy
  21:05:21 - 26/07/2025
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
#define NAME "ATCODER-ABC241D"

void solve()
{
    multiset<int> ms;
    int q;
    cin >> q;
    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
            ms.insert(x);
        else
        {
            int k;
            cin >> k;
            int ans = 0;
            if (t == 2)
            {
                auto it = ms.lower_bound(x + 1);
                for (int i = 0; i < k; i++)
                    if (it == ms.begin())
                    {
                        ans = -1;
                        break;
                    }
                    else
                    {
                        it--;
                        ans = *it;
                    }
            }
            else
            {
                auto it = ms.lower_bound(x);
                for (int i = 0; i < k; i++)
                    if (it == ms.end())
                    {
                        ans = -1;
                        break;
                    }
                    else
                    {
                        ans = *it;
                        it++;
                    }
            }
            cout << ans << '\n';
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
