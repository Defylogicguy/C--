/*************************
  Author: Defy logic guy
  19:48:48 - 04/01/2025
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
#define NAME "ABC_192D"

string s;
int m;

bool f(int mid)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (ans > (m - (s[i] - '0')) / mid)
            return false;
        ans = ans * mid + (s[i] - '0');
    }
    return ans <= m;
}
void solve()
{
    cin >> s;
    cin >> m;
    char _max = *max_element(all(s));
    if (s.size() == 1)
    {
        cout << (_max - '0' <= m ? 1 : 0) << endl;
        return;
    }
    int l = _max - '0' + 1, r = m + 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << max(0ll, ans - (_max - '0')) << endl;
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
