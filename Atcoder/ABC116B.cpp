/*************************
  Author: Defy logic guy
  20:31:12 - 30/05/2025
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
#define NAME "ABC116B"

void solve()
{
    int n;
    cin >> n;
    map<int, bool> check;
    check[n] = true;
    int cnt = 1;
    while (true)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        cnt++;
        if (check[n])
        {
            cout << cnt << endl;
            break;
        }
        check[n] = true;
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
