/*
 Author: Defy logic guy
 23:29:22 - 28/12/2024
*/
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
#define NAME "Skibidi"

pair<int, int> recur(int l, int r, int k)
{
    if (r - l + 1 < k)
        return {0, 0};
    if (r == l)
        return {r, 1};
    int mid = (l + r) / 2;
    if ((r - l + 1) & 1)
    {
        pair<int, int> idk = recur(l, mid - 1, k);
        int one = mid + 2 * idk.first + mid * idk.second;
        return {one, 2 * idk.second + 1};
    }
    else
    {
        pair<int, int> idk = recur(l, mid, k);
        int one = 2 * idk.first + mid * idk.second;
        return {one, 2 * idk.second};
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << recur(1, n, k).first << endl;
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
