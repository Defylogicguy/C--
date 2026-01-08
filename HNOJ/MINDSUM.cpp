/*************************
  Author: Defy logic guy
  20:47:44 - 11/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "MINDSUM"

void solve()
{
    int k;
    cin >> k;
    vector<int> a(k, LLONG_MAX);

    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= 9; i++)
        if (a[i % k] > i)
        {
            a[i % k] = i;
            pq.push({i, i % k});
        }

    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();
        if (a[t.second] < t.first)
            continue;

        for (int i = 0; i <= 9; i++)
            if (a[(t.second * 10 + i) % k] > t.first + i)
            {
                a[(t.second * 10 + i) % k] = t.first + i;
                pq.push({t.first + i, (t.second * 10 + i) % k});
            }
    }

    cout << a[0];
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
