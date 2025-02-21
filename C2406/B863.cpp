/*************************
  Author: Defy logic guy
  19:57:37 - 18/02/2025
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
#define NAME "B863"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heap<int> pq;
    for (int x : a)
        pq.push(x);

    int cnt = 0;
    while (pq.size() > 1)
    {
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        one--, two--;
        if (one != 0)
            pq.push(one);
        if (two != 0)
            pq.push(two);
        cnt++;
    }
    cout << cnt << endl;
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
