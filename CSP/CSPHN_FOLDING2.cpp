/*************************
  Author: Defy logic guy
  14:16:11 - 02/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "CSPHN_FOLDING2"

int n;
char get(int k, int i)
{
    int mid = 1ll << (k - 1);
    if (i == mid)
        return 'A';
    if ((n - k) %  2 == 0)
        return (i < mid ? get(k - 1, i) : 'A' + 'B' - get(k - 1, 2 * mid - i));
    else
        return (i < mid ? 'A' + 'B' - get(k - 1, mid - i) : get(k - 1, i - mid));
}
void solve()
{
    int  i, j;
    cin >> n >> i >> j;
    for (; i <= j; i++)
        cout << get(n, i);
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
