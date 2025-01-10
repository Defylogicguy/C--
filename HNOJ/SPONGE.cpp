/*
 Author: Defy logic guy
 14:09:33 - 31/12/2024
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heap<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
            pq.push(a[i]);
        else
        {
            int tp = pq.top();
            pq.pop();
            pq.push(2 * tp), pq.push(a[i]);
        }
    }
    int sum = accumulate(all(a), 0ll);
    int ans = 0;
    while (pq.size())
        ans += pq.top(), pq.pop();
    cout << ans - sum;
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
